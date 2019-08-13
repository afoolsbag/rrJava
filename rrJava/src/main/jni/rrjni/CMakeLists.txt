cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project(rrjni)

add_library(
  rrjni SHARED "rrjni_JNI.h" "jniaux.hxx" "jniaux.cxx" "impl.cxx")

set_target_properties(
  rrjni
  PROPERTIES CXX_STANDARD          17
             CXX_STANDARD_REQUIRED ON)

target_compile_options(
  rrjni
  PRIVATE "/utf-8")

find_package(JNI REQUIRED)
target_include_directories(
  rrjni
  PRIVATE "${JAVA_INCLUDE_PATH}"
          "${JAVA_INCLUDE_PATH2}")
