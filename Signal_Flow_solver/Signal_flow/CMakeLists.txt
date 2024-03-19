cmake_minimum_required(VERSION 3.5)

project(Signal_flow VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        src/windows/mainwindow.cpp
        headers/windows/mainwindow.h
	src/widgets/toolbar.cpp
        src/widgets/canvas.cpp
	src/widgets/output.cpp
	src/widgets/workspace.cpp
	headers/widgets/toolbar.h
        headers/widgets/canvas.h
	headers/widgets/output.h
	headers/widgets/workspace.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Signal_flow
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        images/new-moon.png images/play.png images/right-arrow.png images/trash-can.png
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Signal_flow APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Signal_flow SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Signal_flow
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Signal_flow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Signal_flow PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Signal_flow
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Signal_flow)
endif()
