cmake_minimum_required(VERSION 3.13)
project(chess)
#set(EXECUTABLE_OUTPUT_PATH /chessbuilds/)

#The includes
include_directories(../chessprogram)

file(GLOB SOURCES src/*.cpp)

#remove from glob
#list(REMOVE_ITEM SOURCES Genius/badcode.cpp)

add_executable(chess ${SOURCES})