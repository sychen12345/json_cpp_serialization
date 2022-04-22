cmake_minimum_required(VERSION 3.10)
project(pageGeneration)
find_package(nlohmann_json 3.2.0 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)


include_directories(${PROJECT_SOURCE_DIR}/developer)
include_directories(${PROJECT_SOURCE_DIR}/pluginsUser)
add_subdirectory(${PROJECT_SOURCE_DIR}/developer)
add_subdirectory(${PROJECT_SOURCE_DIR}/pluginsUser)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json developer pluginsUser)