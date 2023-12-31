cmake_minimum_required(VERSION 3.12)
project(myapi)

# Add the pybind11 library
add_subdirectory(pybind11)

# Set the source files for your project
set(SOURCES
    array.cpp
    api.cpp
)

# Create the shared library
pybind11_add_module(myapi ${SOURCES})
