# Set the project name
project (mylib)

add_library(${PROJECT_NAME} SHARED src/sublib1.cpp)
#add_library(${PROJECT_NAME} STATIC src/sublib1.cpp)

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include    
)
 
