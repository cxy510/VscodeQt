# Set the project name
project (Device)

add_library(${PROJECT_NAME} SHARED src/device.cpp)
#add_library(${PROJECT_NAME} STATIC src/sublib1.cpp)

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include    
)
 
