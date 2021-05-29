CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(text-adventure-game)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(game source/main.cpp source/game_controller.cpp)
ADD_EXECUTABLE(test source/tests.cpp source/game_controller.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)