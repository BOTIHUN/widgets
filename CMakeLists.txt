cmake_minimum_required(VERSION 3.10)
project(widgets)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library(widgets SHARED
src/Button.cpp
src/Widget.cpp
src/Math.cpp
src/SDLSupport.cpp
src/Label.cpp
src/Layout.cpp)

target_include_directories(widgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Add executable
add_executable(widgets-test main.cpp)

target_include_directories(widgets-test PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_ttf_INCLUDE_DIRS})
# Link SDL2
target_link_libraries(widgets-test ${SDL2_LIBRARIES} SDL2_ttf widgets)

# Specify the source folder containing the resources
set(RES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/res")

# Specify the destination folder in the build directory
set(RES_DESTINATION "${CMAKE_BINARY_DIR}/res")

# Add a custom command to copy the folder
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RES_FOLDER} ${RES_DESTINATION}
    COMMENT "Copying resources folder to build directory"
)
