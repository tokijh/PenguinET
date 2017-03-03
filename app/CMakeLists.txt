cmake_minimum_required(VERSION 3.4.1)

# now build app's shared lib
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")

if (${ANDROID_PLATFORM_LEVEL} LESS 11)
    message(FATAL_ERROR "OpenGL 2 is not supported before API level 11 (currently using ${ANDROID_PLATFORM_LEVEL}).")
    return()
elseif (${ANDROID_PLATFORM_LEVEL} LESS 18)
    add_definitions("-DDYNAMIC_ES3")
    set(OPENGL_LIB GLESv2)
else ()
    set(OPENGL_LIB GLESv3)
endif (${ANDROID_PLATFORM_LEVEL} LESS 11)

add_library(gamesystem SHARED
            src/main/cpp/main.cpp
            src/main/cpp/GameSystem.cpp

            src/main/cpp/manager/Save.cpp
            src/main/cpp/manager/AssetsManager.cpp
            src/main/cpp/manager/AssetsShaderManager.cpp

            src/main/cpp/shape/figure/Triangle.cpp
            src/main/cpp/shape/figure/Rectangle.cpp
            src/main/cpp/shape/figure/Circle.cpp
            )

target_link_libraries(gamesystem
                      ${OPENGL_LIB}
                      android
                      EGL
                      log
                      m)

# add_library(gamesystem SHARED
#            src/main/cpp/main.cpp
#            src/main/cpp/GameSystem.cpp)

# add lib dependencies
# target_link_libraries(gamesystem
#                      android
#                      log
#                      EGL
#                      GLESv2)