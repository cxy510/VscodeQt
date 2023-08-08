cmake_minimum_required(VERSION 3.23)
project(ProjectGlory LANGUAGES CXX)

#包含当前路径
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON) #关闭自动生成ui文件,需要指定路径
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON) #关闭自动生成qrc文件,需要指定路径

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

# set(Boost_DEBUG ON)
# set(BOOST_ROOT "D:/ProgTools/boost_1_78_0")    # 指定Boost库的根目录
# set(BOOST_LIBRARIES "D:/ProgTools/boost_1_78_0/stage/libs")    # 指定Boost库的根目录
# set(BOOST_INCLUDE_DIRS "D:/ProgTools/boost_1_78_0")    # 指定Boost库的根目录
set(Boost_USE_STATIC_LIBS ON)    # 设置使用Boost静态库
set(Boost_ARCHITECTURE "-x32")    # 指定库架构为x86
#find_package(Boost 1.78.0 REQUIRED COMPONENTS regex)
#link_directories(${Boost_LIBRARY_DIRS})
#include_directories(${BOOST_ROOT})    # 包含Boost库的头文件目录


# 载入所有Qt的库
find_package(Qt5 COMPONENTS Widgets Gui Sql Core REQUIRED)
# find the protobuf compiler and libraries
#find_package(Protobuf REQUIRED)

# 查找当前文件夹中的所有相关文件
FILE(GLOB SOURCE_FILES  "source/*") 
FILE(GLOB HEADER_FILES  "include/*") 
FILE(GLOB PUBLIC_FILES  "public/*") 
FILE(GLOB IDL_FILES  "protobuf/*") 
FILE(GLOB QRC_FILES  "qrc/*.qrc") 
FILE(GLOB UI_FILES  "ui/*.ui") 
FILE(GLOB CUSTOM_FILES  "../../include/tableview/*") 
#FILE(GLOB INCLUDE_FILES  "../../include/log4qt/*")
FILE(GLOB INCLUDE_FILES  "../../include/log4qt/*" "../../include/log4qt/helpers/*" 
"../../include/log4qt/spi/*" "../../include/log4qt/varia/*") 

#message(111${INCLUDE_FILES})
#message(111${PROJECT_SOURCE_DIR})

# 生成ui.h文件
QT5_WRAP_UI(UI_FILES_H ${UI_FILES})

#使用rcc处理.qrc文件
QT5_ADD_RESOURCES(QRC_FILES_CPP ${QRC_FILES})
 
#生成可执行文件
ADD_EXECUTABLE(ProjectGlory 
    main.cpp    
    ${INCLUDE_FILES}   
    ${SOURCE_FILES} 
    ${HEADER_FILES} 
    ${PUBLIC_FILES} 
    ${UI_FILES_H}  
    ${QRC_FILES_CPP}       
    ${CUSTOM_FILES}  
    ${IDL_FILES}       
)

target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/../../include/)
target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/../../include/log4qt/)
target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(ProjectGlory PRIVATE ${PROJECT_SOURCE_DIR}/protobuf)

add_subdirectory(subdevice) #如果有该条语句，就先会跑去执行子项目的cmake代码
add_subdirectory(subthreadpool)
add_subdirectory(subanalyzesqlite)
add_subdirectory(subziptool)


# 导入lib库
target_link_libraries(ProjectGlory PRIVATE Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Core)  
target_link_libraries(ProjectGlory PRIVATE Device ThreadPool AnalyzeSqlite ZipTool)


set(LIB_DIR ${PROJECT_SOURCE_DIR}/../../lib/)
#FILE(GLOB PROTOBUF_LIB  "../../lib/protobuf3.3/*.a" "../../lib/mpi/x86/msmpi.lib") 
FILE(GLOB LIB_LIST  ${LIB_DIR}protobuf3.3/*.a ${LIB_DIR}mpi/x86/msmpi.lib) 
target_link_libraries(ProjectGlory PRIVATE ${LIB_LIST})

# 设置dll路径与执行程序在同一路径下
SET_TARGET_PROPERTIES(ZipTool Device ThreadPool AnalyzeSqlite ProjectGlory PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../bin/)
