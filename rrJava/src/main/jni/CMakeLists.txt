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

target_include_directories(
  rrjni PRIVATE "$ENV{JAVA_HOME}/include")

if(UNIX)
  target_include_directories(
    rrjni PRIVATE "$ENV{JAVA_HOME}/include/linux")
endif()
if(WIN32)
  target_include_directories(
    rrjni PRIVATE "$ENV{JAVA_HOME}/include/win32")
endif()
