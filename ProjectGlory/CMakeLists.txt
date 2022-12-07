cmake_minimum_required(VERSION 3.5)

project(ProjectGlory LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON) #关闭自动生成ui文件,需要指定路径
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON) #关闭自动生成qrc文件,需要指定路径

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 


find_package(Qt5 COMPONENTS Widgets Gui REQUIRED)

# 查找当前文件夹中的所有相关文件
FILE(GLOB SOURCE_FILES  "source/*") 
FILE(GLOB HEADER_FILES  "include/*") 
FILE(GLOB QRC_FILES  "qrc/*.qrc") 
FILE(GLOB UI_FILES  "ui/*.ui") 

# 生成ui.h文件
QT5_WRAP_UI(UI_FILES_H ${UI_FILES})

#使用rcc处理.qrc文件
QT5_ADD_RESOURCES(QRC_FILES_CPP ${QRC_FILES})
 
#生成可执行文件
ADD_EXECUTABLE(ProjectGlory 
    main.cpp
    ${SOURCE_FILES} 
    ${HEADER_FILES} 
    ${UI_FILES_H}  
    ${QRC_FILES_CPP}     
)

target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(ProjectGlory PRIVATE Qt5::Widgets Qt5::Gui) 
