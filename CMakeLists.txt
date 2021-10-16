cmake_minimum_required(VERSION 3.20)
project(QMapperTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QMapperTest main.cpp mapperWindow.cpp mapperWindow.h PreguntaRespuesta.cpp PreguntaRespuesta.h)
target_link_libraries(QMapperTest
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

