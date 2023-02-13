# Set the project name
# SET(ProjectName "AnalyzeSqlite")
project(AnalyzeSqlite)

find_package(Qt5Sql)
find_package(Qt5Gui)
find_package(Qt5Core)

# 查找当前文件夹中的所有相关文件
FILE(GLOB SOURCE_FILES  "src/*") 
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES}) 

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include    
) 

# 导入lib库
target_link_libraries(${PROJECT_NAME}  PRIVATE Qt5::Sql Qt5::Gui Qt5::Core) 

