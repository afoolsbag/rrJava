//===-- JNI Auxiliary -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief JNI 辅助工具
///
/// \sa <https://www.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html>
/// \sa <https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html>
///
/// \version 2019-06-29
/// \since 2019-06-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef JNIAUX_HXX_
#define JNIAUX_HXX_

#include <exception>
#include <stdexcept>
#include <string>
#include <vector>

#include <jni.h>

#define JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(elem)                           \
std::vector<elem> jtostd(JNIEnv *jenv, elem##Array jarr);

#define JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(elem)                           \
elem##Array stdtoj(JNIEnv *jenv, const std::vector<elem> &stdvec);

#define JNIAUX_THROW_JEXCEPTION_DECLARATION(name)                              \
jint throw_##name(JNIEnv *jenv, const std::string &message) noexcept;

namespace jniaux {

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jbyte);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jbyte);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jshort);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jshort);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jint);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jint);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jlong);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jlong);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jfloat);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jfloat);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jdouble);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jdouble);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jchar);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jchar);

JNIAUX_JARRAY_TO_STDVECTOR_DECLARATION(jboolean);
JNIAUX_STDVECTOR_TO_JARRAY_DECLARATION(jboolean);

std::string jtostd(JNIEnv *jenv, jstring jstr);
jstring stdtoj(JNIEnv *jenv, const std::string &stdstr);

/// \warning 简明 `jtostd` 将 `jobjectArray` 视作 `jstringArray`，其他类型 `jobjectArray` 请使用相应命名函数
std::vector<std::string> jtostd(JNIEnv *jenv, jobjectArray jstrarr);
jobjectArray stdtoj(JNIEnv *jenv, const std::vector<std::string> &stdvec);

JNIAUX_THROW_JEXCEPTION_DECLARATION(Exception);
JNIAUX_THROW_JEXCEPTION_DECLARATION(IllegalArgumentException);
JNIAUX_THROW_JEXCEPTION_DECLARATION(IndexOutOfBoundsException);
JNIAUX_THROW_JEXCEPTION_DECLARATION(NoClassDefFoundError);
JNIAUX_THROW_JEXCEPTION_DECLARATION(RuntimeException);

};

#define JNIAUX_STDEXCEPTION_TO_JEXCEPTION_TRY                                  \
    try {
#define JNIAUX_STDEXCEPTION_TO_JEXCEPTION_CATCH(jenv, ...)                     \
    } catch (const std::invalid_argument &e) {                                 \
        jniaux::throw_IllegalArgumentException(jenv, e.what());                \
        return __VA_ARGS__;                                                    \
    } catch (const std::out_of_range &e) {                                     \
        jniaux::throw_IndexOutOfBoundsException(jenv, e.what());               \
        return __VA_ARGS__;                                                    \
    } catch (const std::runtime_error &e) {                                    \
        jniaux::throw_RuntimeException(jenv, e.what());                        \
        return __VA_ARGS__;                                                    \
    } catch (const std::exception &e) {                                        \
        jniaux::throw_Exception(jenv, e.what());                               \
        return __VA_ARGS__;                                                    \
    } catch (...) {                                                            \
        jniaux::throw_Exception(jenv, "unexpected exception");                 \
        return __VA_ARGS__;                                                    \
    }

#endif
