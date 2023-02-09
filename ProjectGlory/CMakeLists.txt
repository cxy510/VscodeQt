cmake_minimum_required(VERSION 3.5)

project(ProjectGlory LANGUAGES CXX)

#包含当前路径
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON) #关闭自动生成ui文件,需要指定路径
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON) #关闭自动生成qrc文件,需要指定路径

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

#find_package(Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package (Qt5Core)
find_package (Qt5Widgets)
find_package (Qt5Gui)

message(111${CMAKE_SOURCE_DIR})


# 查找当前文件夹中的所有相关文件
FILE(GLOB SOURCE_FILES  "source/*") 
FILE(GLOB HEADER_FILES  "include/*") 
FILE(GLOB QRC_FILES  "qrc/*.qrc") 
FILE(GLOB UI_FILES  "ui/*.ui") 
FILE(GLOB CUSTOM_FILES  "custom/*") 

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
    ${CUSTOM_FILES}  
)
# Add sub directories
# add_subdirectory(sublibrary1)
add_subdirectory(subdevice)
add_subdirectory(subthreadpool)
add_subdirectory(subanalyzesqlite)

target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/custom)

# 导入lib库
target_link_libraries(ProjectGlory PRIVATE Qt5::Widgets Qt5::Gui) 
# target_link_libraries(ProjectGlory PRIVATE mylib)
target_link_libraries(ProjectGlory PRIVATE Device)
target_link_libraries(ProjectGlory PRIVATE ThreadPool)
target_link_libraries(ProjectGlory PRIVATE AnalyzeSqlite)

# 设置dll路径与执行程序在同一路径下
# SET_TARGET_PROPERTIES(mylib PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/build)
SET_TARGET_PROPERTIES(Device PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/build)
SET_TARGET_PROPERTIES(ThreadPool PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/build)
SET_TARGET_PROPERTIES(AnalyzeSqlite PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/build)
