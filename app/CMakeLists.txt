cmake_minimum_required(VERSION 3.4.1)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_library(gamesystem SHARED
            src/main/cpp/main.cpp
            src/main/cpp/GameSystem.cpp)

# add lib dependencies
target_link_libraries(gamesystem
                      android
                      log
                      EGL
                      GLESv2)

# cmake_minimum_required(VERSION 3.4.1)

# add_library(
#              native-lib
#              SHARED
#              src/main/cpp/native-lib.cpp )

# find_library(
#              log-lib
#              log )

# target_link_libraries(
#                       native-lib
#                       ${log-lib} )