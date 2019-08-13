#include "jniaux.hxx"

#include <functional>
#include <memory>

using namespace std;

namespace {

/// \brief Java array to (C++) std vector
/// \tparam Array   数组类型，如 `jbyteArray`
/// \tparam Elem    元素类型，如 `jbyte`
/// \tparam Get     `JNIEnv` 的 `Get*ArrayElements` 方法
/// \tparam Release `JNIEnv` 的 `Release*ArrayElements` 方法
template<
    typename Array,
    typename Elem,
    Elem *(JNIEnv::*Get)(Array, jboolean *),
    void (JNIEnv::*Release)(Array, Elem *, jint)
> vector<Elem> basic_jarray_to_stdvector(JNIEnv *jenv, Array jarr)
{
    if (!jenv || !jarr)
        throw invalid_argument(__func__ + " not accept nullptr"s);

    const auto del = bind(Release, jenv, jarr, placeholders::_1, 0);
    const unique_ptr<Elem[], decltype(del)> buf {(jenv->*Get)(jarr, nullptr), del};
    if (!buf)
        throw runtime_error(__func__ + " Get*ArrayElements failed"s);

    const auto len = jenv->GetArrayLength(jarr);
    return {buf.get(), buf.get() + len};
}

/// \brief “C++ 向量转 Java 数组”模板
/// \tparam Array 数组类型，如 `jbyteArray`
/// \tparam Elem  元素类型，如 `jbyte`
/// \tparam New   `JNIEnv` 的 `New*Array` 方法
/// \tparam Set   `JNIEnv` 的 `Set*ArrayRegion` 方法
template<
    typename Array,
    typename Elem,
    Array(JNIEnv::*New)(jsize),
    void (JNIEnv::*Set)(Array, jsize, jsize, const Elem *)
> Array basic_stdvector_to_jarray(JNIEnv *jenv, const vector<Elem> &stdvec)
{
    if (!jenv)
        throw invalid_argument(__func__ + " not accept nullptr"s);

    const auto jobj = (jenv->*New)(static_cast<jsize>(stdvec.size()));
    if (!jobj)
        throw runtime_error(__func__ + " Set*ArrayRegion failed"s);
    (jenv->*Set)(jobj, 0, static_cast<jsize>(stdvec.size()), stdvec.data());
    return jobj;
}

enum : jint {
    throw_ok = 0,
    throw_jenv_nullptr,
    throw_NoClassDefFoundError_not_fount,
};

}

#define JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(Elem, Stem)                      \
std::vector<Elem> jtostd(JNIEnv *jenv, Elem##Array jarr)                       \
{                                                                              \
    return basic_jarray_to_stdvector<Elem##Array, Elem, &JNIEnv::Get##Stem##ArrayElements, &JNIEnv::Release##Stem##ArrayElements>(jenv, jarr); \
}

#define JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(Elem, Stem)                      \
Elem##Array stdtoj(JNIEnv *jenv, const std::vector<Elem> &stdvec)              \
{                                                                              \
    return basic_stdvector_to_jarray<Elem##Array, Elem, &JNIEnv::New##Stem##Array, &JNIEnv::Set##Stem##ArrayRegion>(jenv, stdvec); \
}

#define JNIAUX_THROW_JEXCEPTION_DEFINITION(name)                               \
jint throw_##name(JNIEnv *jenv, const std::string &message) noexcept           \
{                                                                              \
    constexpr auto class_name {"java/lang/" #name};                            \
    if (!jenv)                                                                 \
        return throw_jenv_nullptr;                                             \
    const auto exception_class = jenv->FindClass(class_name);                  \
    if (!exception_class)                                                      \
        return throw_NoClassDefFoundError(jenv, class_name);                   \
    return jenv->ThrowNew(exception_class, message.c_str());                   \
}

namespace jniaux {

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jbyte, Byte);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jbyte, Byte);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jshort, Short);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jshort, Short);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jint, Int);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jint, Int);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jlong, Long);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jlong, Long);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jfloat, Float);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jfloat, Float);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jdouble, Double);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jdouble, Double);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jchar, Char);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jchar, Char);

JNIAUX_JARRAY_TO_STDVECTOR_DEFINITION(jboolean, Boolean);
JNIAUX_STDVECTOR_TO_JARRAY_DEFINITION(jboolean, Boolean);

string jtostd(JNIEnv *jenv, jstring jstr)
{
    if (!jenv || !jstr)
        throw invalid_argument(__func__ + " not accept nullptr"s);

    const auto del = bind(&JNIEnv::ReleaseStringUTFChars, jenv, jstr, placeholders::_1);
    const unique_ptr<const char[], decltype(del)> buf {jenv->GetStringUTFChars(jstr, nullptr), del};
    if (!buf)
        throw runtime_error(__func__ + " GetStringUTFChars failed"s);
    return buf.get();
}

jstring stdtoj(JNIEnv *jenv, const string &stdstr)
{
    if (!jenv)
        throw invalid_argument(__func__ + " not accept nullptr"s);

    return jenv->NewStringUTF(stdstr.c_str());
}

vector<string> jtostd(JNIEnv *jenv, jobjectArray jstrarr)
{
    if (!jenv || !jstrarr)
        throw invalid_argument(__func__ + " not accept nullptr"s);

    vector<string> stdvec;
    const auto length = jenv->GetArrayLength(jstrarr);
    for (jsize i = 0; i < length; ++i) {
        const auto jstr = reinterpret_cast<jstring>(jenv->GetObjectArrayElement(jstrarr, i));
        if (!jstr)
            throw runtime_error(__func__ + " GetObjectArrayElement failed"s);

        const auto del = bind(&JNIEnv::ReleaseStringUTFChars, jenv, jstr, placeholders::_1);
        const unique_ptr<const char[], decltype(del)> buf {jenv->GetStringUTFChars(jstr, nullptr), del};
        if (!buf)
            throw runtime_error(__func__ + " GetStringUTFChars failed"s);

        stdvec.emplace_back(buf.get());
    }
    return stdvec;
}

jobjectArray stdtoj(JNIEnv *jenv, const vector<string> &stdvec)
{
    if (!jenv)
        throw invalid_argument(__func__ + " not accept nullptr"s);

    const auto string_class = jenv->FindClass("java/lang/String");
    if (!string_class)
        throw runtime_error(__func__ + " FindClass failed"s);

    const auto initial_value = jenv->NewStringUTF("");
    if (!initial_value)
        throw runtime_error(__func__ + " NewStringUTF failed"s);

    const auto jobj = jenv->NewObjectArray(static_cast<jsize>(stdvec.size()), string_class, initial_value);
    if (!jobj)
        throw runtime_error(__func__ + " NewObjectArray failed"s);

    for (size_t i = 0; i < stdvec.size(); ++i) {
        const auto jstr = jenv->NewStringUTF(stdvec[i].c_str());
        if (!jstr)
            throw runtime_error(__func__ + " NewStringUTF failed"s);
        jenv->SetObjectArrayElement(jobj, static_cast<jsize>(i), jstr);
    }

    return jobj;
}

JNIAUX_THROW_JEXCEPTION_DEFINITION(Exception);
JNIAUX_THROW_JEXCEPTION_DEFINITION(IllegalArgumentException);
JNIAUX_THROW_JEXCEPTION_DEFINITION(IndexOutOfBoundsException);

jint throw_NoClassDefFoundError(JNIEnv *jenv, const std::string &message) noexcept
{
    constexpr auto class_name {"java/lang/NoClassDefFoundError"};
    if (!jenv)
        return throw_jenv_nullptr;
    const auto exception_class = jenv->FindClass(class_name);
    if (!exception_class)
        return throw_NoClassDefFoundError_not_fount;
    return jenv->ThrowNew(exception_class, message.c_str());
}

JNIAUX_THROW_JEXCEPTION_DEFINITION(RuntimeException);

}
