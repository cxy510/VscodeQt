# Set the project name
project (ZipTool)

find_package(Qt5Core)

add_library(${PROJECT_NAME} SHARED src/ziptool.cpp)

target_include_directories( ${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/../../../include/quazip)
target_include_directories( ${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/include )
 
# 导入lib库

set(LIB_DIR ${PROJECT_SOURCE_DIR}/../../../lib/)
FILE(GLOB LIB_LIST  ${LIB_DIR}zlib/*.a ${LIB_DIR}quazip/libquazip.a) 
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_LIST} Qt5::Core)

