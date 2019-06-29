#include "rrjni_JNI.h"

#include <cstdio>

#include "jniaux.hxx"

using namespace std;

extern "C" JNIEXPORT void
JNICALL Java_rrjni_JNI_ioVoid(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %s\n", __func__, "void");
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv);
}

extern "C" JNIEXPORT jbyte
JNICALL Java_rrjni_JNI_ioByte(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jbyte jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %hhd\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jbyteArray
JNICALL Java_rrjni_JNI_ioByteArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jbyteArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %hhd\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jshort
JNICALL Java_rrjni_JNI_ioShort(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jshort jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %hd\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jshortArray
JNICALL Java_rrjni_JNI_ioShortArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jshortArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %hd\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jint
JNICALL Java_rrjni_JNI_ioInt(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jint jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %ld\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jintArray
JNICALL Java_rrjni_JNI_ioIntArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jintArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %ld\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jlong
JNICALL Java_rrjni_JNI_ioLong(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jlong jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %lld\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jlongArray
JNICALL Java_rrjni_JNI_ioLongArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jlongArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %lld\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jfloat
JNICALL Java_rrjni_JNI_ioFloat(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jfloat jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %f\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jfloatArray
JNICALL Java_rrjni_JNI_ioFloatArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jfloatArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %f\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jdouble
JNICALL Java_rrjni_JNI_ioDouble(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jdouble jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %lf\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jdoubleArray
JNICALL Java_rrjni_JNI_ioDoubleArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jdoubleArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %lf\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jchar
JNICALL Java_rrjni_JNI_ioChar(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jchar jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %hu\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jcharArray
JNICALL Java_rrjni_JNI_ioCharArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jcharArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %hu\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jboolean
JNICALL Java_rrjni_JNI_ioBoolean(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jboolean jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    printf("%s: %hhu\n", __func__, jin);
    return jin;
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, jin);
}

extern "C" JNIEXPORT jbooleanArray
JNICALL Java_rrjni_JNI_ioBooleanArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jbooleanArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %hhu\n", __func__, i);
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jstring
JNICALL Java_rrjni_JNI_ioString(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jstring jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    printf("%s: %s\n", __func__, in.c_str());
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}

extern "C" JNIEXPORT jobjectArray
JNICALL Java_rrjni_JNI_ioStringArray(
    [[maybe_unused]] JNIEnv *jenv,
    [[maybe_unused]] jobject jthis,
    jobjectArray jin)
{
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY;
    const auto in = jniaux::jtostd(jenv, jin);
    for (const auto &i : in)
        printf("%s: %s\n", __func__, i.c_str());
    return jniaux::stdtoj(jenv, in);
    JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, nullptr);
}
