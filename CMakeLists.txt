cmake_minimum_required(VERSION 3.10)
project(widgets)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add executable
add_executable(widgets-test main.cpp Math.cpp Button.cpp Widget.cpp SDLSupport.cpp)

target_include_directories(widgets-test PRIVATE ${SDL2_INCLUDE_DIRS})
# Link SDL2
target_link_libraries(widgets-test ${SDL2_LIBRARIES})
