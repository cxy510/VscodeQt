# Set the project name
project (ZipTool)

#find_package (Qt5Network)
# message(111${Qt5Network_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED src/ziptool.cpp)

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include    
)
 

#target_link_libraries(ZipTool PRIVATE Qt5::Network) 

