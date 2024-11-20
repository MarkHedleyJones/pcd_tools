cmake_minimum_required(VERSION 3.10)

# Set the project name
project(pcd_tools)

# Find the PCL package
find_package(PCL 1.9 REQUIRED)

# Set the executable target
add_executable(pcd_concatenate src/pcd_concatenate.cpp)

# Include PCL headers
include_directories(${PCL_INCLUDE_DIRS})

# Link PCL libraries
target_link_libraries(pcd_concatenate ${PCL_LIBRARIES})

# Set compilation flags
add_definitions(${PCL_DEFINITIONS})
