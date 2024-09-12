cmake_minimum_required(VERSION 3.14)

project(Calculator LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QML_IMPORT_PATH /Users/mac/Desktop/repos/guicalculator/qml)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml Gui)

set(SOURCES
    src/main.cpp
    src/mathOperations.cpp
    include/mathOperations.h
)

qt_add_executable(Calculator MACOSX_BUNDLE
    ${SOURCES}
    ${CALCULATOR_ICON}
)
if(ANDROID)
  set(CMAKE_ANDROID_API 23)

  set(CMAKE_ANDROID_ARCH_ABI "arm64-v8a")

  set(CALCULATOR_ICON "${CMAKE_CURRENT_SOURCE_DIR}/CalculatorPng.png")

  set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  message(STATUS "ANDROID_PACKAGE_SOURCE_DIR: ${ANDROID_PACKAGE_SOURCE_DIR}")

  set_source_files_properties(${CALCULATOR_ICON} PROPERTIES
      ANDROID_PACKAGE_SOURCE_DIR "res/drawable"
  )

  set_target_properties(Calculator PROPERTIES
      ANDROID_GUI TRUE
      OUTPUT_NAME "Calculator"
      QT_ANDROID_PACKAGE_SOURCE_DIR "${ANDROID_PACKAGE_SOURCE_DIR}"
  )

include(/Users/mac/Library/Android/sdk/android_openssl/CMakeLists.txt)
endif()

if(APPLE)

set(CMAKE_OSX_BUNDLE TRUE)

set(CALCULATOR_ICON "${CMAKE_CURRENT_SOURCE_DIR}/Calculator.icns")

set_source_files_properties(${CALCULATOR_ICON} PROPERTIES
    MACOSX_PACKAGE_LOCATION "Resources"
)

set_target_properties(Calculator PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_ICON_FILE "Calculator.icns"
    RESOURCE "${CALCULATOR_ICON}"
)
endif()

qt_policy(SET QTP0001 NEW)

qt_add_qml_module(Calculator
    URI guiCalculator
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/StyledButton.qml
        qml/Buttons.qml
        RESOURCES qml.qrc
)

target_include_directories(Calculator PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Calculator PRIVATE Qt6::Core Qt6::Quick Qt6::Gui)
