cmake_minimum_required(VERSION 3.23)
project(ProjectAlarmQml LANGUAGES CXX)

#包含当前路径
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON) #关闭自动生成ui文件,需要指定路径
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON) #关闭自动生成qrc文件,需要指定路径

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 




# 载入所有Qt的库
find_package(Qt5 COMPONENTS quick REQUIRED)
# find the protobuf compiler and libraries
#find_package(Protobuf REQUIRED)

# 查找当前文件夹中的所有相关文件
FILE(GLOB SOURCE_FILES  "source/*") 
FILE(GLOB HEADER_FILES  "include/*") 
FILE(GLOB QRC_FILES  "qrc/*.qrc") 



#使用rcc处理.qrc文件
QT5_ADD_RESOURCES(QRC_FILES_CPP ${QRC_FILES})
 
#生成可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} 
    main.cpp    
    ${SOURCE_FILES} 
    ${HEADER_FILES} 
    ${QRC_FILES_CPP}     
)


# 导入lib库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Quick)  


# 设置dll路径与执行程序在同一路径下
SET_TARGET_PROPERTIES(${PROJECT_NAME}  PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../bin/)
