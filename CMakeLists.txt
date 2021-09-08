cmake_minimum_required(VERSION 3.20)
project(bsf_statemachine)

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

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(bsf_statemachine
        PavementMachine.h
        PavementMachine.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.h
        statemachine/LiftEvent.cpp
        statemachine/LiftEvent.h
        statemachine/events/LiftIdle.cpp
        statemachine/events/LiftIdle.h
        statemachine/events/LiftMoving.cpp
        statemachine/events/LiftMoving.h
        statemachine/events/LiftArrived.cpp
        statemachine/events/LiftArrived.h
        statemachine/events/LiftEventData.h)

target_link_libraries(bsf_statemachine
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

