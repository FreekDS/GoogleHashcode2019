INCLUDE_DIRECTORIES(include)
cmake_minimum_required(VERSION 3.12)
SET(SRC
        src/main.cpp
        src/PizzaParser.cpp
        src/poging1.cpp
        )

FILE(COPY input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY out DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(pizzaSlicer6000 ${SRC})

