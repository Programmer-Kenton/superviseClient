cmake_minimum_required(VERSION 3.27)
project(superviseClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/QT/6.5.3/mingw_64")
set(OpenCV_DIR "E:/OpenCV/opencv/MinGW-build/install")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

find_package(
        OpenCV
        REQUIRED
)

# 添加OpenCV头文件的搜索路径
include_directories(${OpenCV_INCLUDE_DIRS})

qt_add_resources(
        haarcascade_eye.xml
        haarcascade_eye_tree_eyeglasses.xml
        haarcascade_frontalcatface.xml
        haarcascade_frontalcatface_extended.xml
        haarcascade_frontalface_alt.xml
        haarcascade_frontalface_alt2.xml
        haarcascade_frontalface_alt_tree.xml
        haarcascade_frontalface_default.xml
        haarcascade_fullbody.xml
        haarcascade_lefteye_2splits.xml
        haarcascade_license_plate_rus_16stages.xml
        haarcascade_lowerbody.xml
        haarcascade_profileface.xml
        haarcascade_righteye_2splits.xml
        haarcascade_russian_plate_number.xml
        haarcascade_smile.xml
        haarcascade_upperbody.xml
)

add_executable(
        superviseClient main.cpp
        head/superviseClientWidget.h
        head/FaceDetection.h
        source/superviseClientWidget.cpp
        source/FaceDetection.cpp
        ui/superviseClientWidget.ui
)

target_link_libraries(superviseClient
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        ${OpenCV_LIBS}
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Network)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
