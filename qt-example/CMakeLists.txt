find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt-statemachine
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        StringTransition.h LiftTransition.h state/LiftIdleState.h)

target_link_libraries(qt-statemachine
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )