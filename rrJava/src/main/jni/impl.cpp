/// \sa <https://www.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html>
///
/// \copyright Unlicense

#include "rrjni_JNI.h"

#include <functional>
#include <memory>
#include <vector>

using namespace std;

extern "C" JNIEXPORT void
JNICALL Java_rrjni_JNI_ioVoid(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis)
{}

extern "C" JNIEXPORT jbyte
JNICALL Java_rrjni_JNI_ioByte(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jbyte jin)
{
    return jin;
}

extern "C" JNIEXPORT jbyteArray
JNICALL Java_rrjni_JNI_ioByteArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jbyteArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseByteArrayElements, env, jin, _1, 0);

    const unique_ptr<jbyte[], decltype(deleter)> in {env->GetByteArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jbyte> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewByteArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetByteArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jshort
JNICALL Java_rrjni_JNI_ioShort(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jshort jin)
{
    return jin;
}

extern "C" JNIEXPORT jshortArray
JNICALL Java_rrjni_JNI_ioShortArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jshortArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseShortArrayElements, env, jin, _1, 0);

    const unique_ptr<jshort[], decltype(deleter)> in {env->GetShortArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jshort> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewShortArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetShortArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jint
JNICALL Java_rrjni_JNI_ioInt(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jint jin)
{
    return jin;
}

extern "C" JNIEXPORT jintArray
JNICALL Java_rrjni_JNI_ioIntArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jintArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseIntArrayElements, env, jin, _1, 0);

    const unique_ptr<jint[], decltype(deleter)> in {env->GetIntArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jint> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewIntArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetIntArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jlong
JNICALL Java_rrjni_JNI_ioLong(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jlong jin)
{
    return jin;
}

extern "C" JNIEXPORT jlongArray
JNICALL Java_rrjni_JNI_ioLongArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jlongArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseLongArrayElements, env, jin, _1, 0);

    const unique_ptr<jlong[], decltype(deleter)> in {env->GetLongArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jlong> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewLongArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetLongArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jfloat
JNICALL Java_rrjni_JNI_ioFloat(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jfloat jin)
{
    return jin;
}

extern "C" JNIEXPORT jfloatArray
JNICALL Java_rrjni_JNI_ioFloatArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jfloatArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseFloatArrayElements, env, jin, _1, 0);

    const unique_ptr<jfloat[], decltype(deleter)> in {env->GetFloatArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jfloat> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewFloatArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetFloatArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jdouble
JNICALL Java_rrjni_JNI_ioDouble(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jdouble jin)
{
    return jin;
}

extern "C" JNIEXPORT jdoubleArray
JNICALL Java_rrjni_JNI_ioDoubleArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jdoubleArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseDoubleArrayElements, env, jin, _1, 0);

    const unique_ptr<jdouble[], decltype(deleter)> in {env->GetDoubleArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jdouble> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewDoubleArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetDoubleArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jchar
JNICALL Java_rrjni_JNI_ioChar(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jchar jin)
{
    return jin;
}

extern "C" JNIEXPORT jcharArray
JNICALL Java_rrjni_JNI_ioCharArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jcharArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseCharArrayElements, env, jin, _1, 0);

    const unique_ptr<jchar[], decltype(deleter)> in {env->GetCharArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jchar> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewCharArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetCharArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jboolean
JNICALL Java_rrjni_JNI_ioBoolean(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jboolean jin)
{
    return jin;
}

extern "C" JNIEXPORT jbooleanArray
JNICALL Java_rrjni_JNI_ioBooleanArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jbooleanArray jin)
{
    using namespace placeholders;
    const auto deleter = bind(&JNIEnv::ReleaseBooleanArrayElements, env, jin, _1, 0);

    const unique_ptr<jboolean[], decltype(deleter)> in {env->GetBooleanArrayElements(jin, nullptr), deleter};
    if (!in)
        return nullptr;
    const auto inlen = env->GetArrayLength(jin);

    vector<jboolean> out;
    for (jsize i = 0; i < inlen; ++i)
        out.push_back(in[i]);

    const auto jout = env->NewBooleanArray(static_cast<jsize>(out.size()));
    if (!jout)
        return nullptr;
    env->SetBooleanArrayRegion(jout, 0, static_cast<jsize>(out.size()), out.data());
    return jout;
}

extern "C" JNIEXPORT jstring
JNICALL Java_rrjni_JNI_ioString(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jstring jin)
{
    using namespace placeholders;

    const auto deleter = bind(&JNIEnv::ReleaseStringUTFChars, env, jin, _1);
    const unique_ptr<const char[], decltype(deleter)> in {env->GetStringUTFChars(jin, nullptr), deleter};
    if (!in)
        return nullptr;

    const string out {in.get()};

    const auto jout = env->NewStringUTF(out.c_str());
    if (!jout)
        return nullptr;
    return jout;
}

extern "C" JNIEXPORT jobjectArray
JNICALL Java_rrjni_JNI_ioStringArray(
    [[maybe_unused]] JNIEnv *env,
    [[maybe_unused]] jobject jthis,
    jobjectArray jin)
{
    using namespace placeholders;

    const auto jString = env->FindClass("java/lang/String");
    if (!jString)
        return nullptr;

    vector<string> in;
    const auto inlen = env->GetArrayLength(jin);
    for (jsize i = 0; i < inlen; ++i) {
        const auto jstr = reinterpret_cast<jstring>(env->GetObjectArrayElement(jin, i));
        if (!jstr)
            return nullptr;

        const auto deleter = bind(&JNIEnv::ReleaseStringUTFChars, env, jstr, _1);
        const unique_ptr<const char[], decltype(deleter)> str {env->GetStringUTFChars(jstr, nullptr), deleter};
        if (!str)
            return nullptr;

        in.emplace_back(str.get());
    }

    const auto out = in;

    const auto init = env->NewStringUTF("");
    if (!init)
        return nullptr;
    const auto jout = env->NewObjectArray(static_cast<jsize>(out.size()), jString, init);
    for (size_t i = 0; i < out.size(); ++i) {
        const auto jstr = env->NewStringUTF(out[i].c_str());
        if (!jstr)
            return nullptr;
        env->SetObjectArrayElement(jout, static_cast<jsize>(i), jstr);
    }
    return jout;
}
