cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(PROJECT_NAME libgdps)
project(${PROJECT_NAME})

find_file(WINDOWS_HEADER windows.h)
if(NOT WINDOWS_HEADER)
  message(FATAL_ERROR "Can't find windows.h!")
endif()

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES}  "src/Miscellaneous/Utils.h")

target_include_directories(${PROJECT_NAME} PRIVATE
  libraries/fmt/
  libraries/fmt/include
  libraries/Discord/
  libraries/Discord/include
  libraries/OpenSSL/
  libraries/OpenSSL/include
  libraries/minhook/include
  libraries/FMOD/
  libraries/FMOD/include
  libraries/GeometryDash/
  libraries/GeometryDash/include
  libraries/cocos-headers/cocos2dx/
  libraries/cocos-headers/cocos2dx/include
  libraries/cocos-headers/cocos2dx/touch_dispatcher/
  libraries/cocos-headers/cocos2dx/kazmath/include
  libraries/cocos-headers/cocos2dx/platform/win32
  libraries/cocos-headers/cocos2dx/platform/third_party/win32
  libraries/cocos-headers/cocos2dx/platform/third_party/win32/OGLES
  libraries/cocos-headers/extensions/
  libraries/cocos-headers/extensions/include
)



target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/Discord/lib/discord-rpc.lib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/OpenSSl/lib/libcrypto.lib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/OpenSSl/lib/libssl.lib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/fmt/fmt.lib)

add_subdirectory(libraries/minhook)
target_link_libraries(${PROJECT_NAME} minhook)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/FMOD/fmod.lib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/cocos-headers/cocos2dx/libcocos2d.lib)
# not needed most of the time
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libraries/cocos-headers/extensions/libExtensions.lib)

