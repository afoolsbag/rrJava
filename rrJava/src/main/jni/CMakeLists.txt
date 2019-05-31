cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)

project(rrjni)

add_library(
  rrjni SHARED "rrjni_JNI.h" "impl.cpp")
set_target_properties(
  rrjni PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
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
