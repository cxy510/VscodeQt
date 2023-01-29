# Set the project name
project (ThreadPool)

#find_package (Qt5Network)
# message(111${Qt5Network_INCLUDE_DIRS})

# 查找当前文件夹中的所有相关文件
FILE(GLOB SOURCE_FILES  "src/*") 
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES}) 

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include    
) 

#target_link_libraries(Device PRIVATE Qt5::Network) 

