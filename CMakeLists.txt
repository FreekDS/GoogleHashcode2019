CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(Hashcode)
SET(CMAKE_CXX_STANDARD 14)

SET(SRC main.cpp
        PhotoParser.cpp
        PhotoParser.h)

ADD_EXECUTABLE(run
        ${SRC})