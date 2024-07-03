cmake_minimum_required(VERSION 3.14)

project(Signals-Slots-in-Qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Signals-Slots-in-Qt
  main.cpp
  Firefox.cpp internetexplorer.cpp UserInteractor.cpp
  Firefox.h internetexplorer.h UserInteractor.h
)
target_link_libraries(Signals-Slots-in-Qt Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Signals-Slots-in-Qt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
