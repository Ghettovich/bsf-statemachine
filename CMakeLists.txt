cmake_minimum_required(VERSION 3.20)
project(qt-stringtransition)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(QT_LOCATION "" CACHE PATH "[Required] QT Location")
if (NOT QT_LOCATION)
    message(FATAL_ERROR "'QT_LOCATION' variable is required but was not set.")
else ()
    message(STATUS "Using QT at: ${QT_LOCATION}")
endif ()

set(CMAKE_PREFIX_PATH "${QT_LOCATION}")

add_subdirectory(qt-example)