cmake_minimum_required(VERSION 3.28)
project(ThreeInRowProject LANGUAGES CXX)

# add the program executable
add_executable(ThreeInRow)
target_sources(ThreeInRow PRIVATE ${CMAKE_SOURCE_DIR}/src/threeinrow/main.cpp)

# SFML needs C++ 17 or higher
target_compile_features(ThreeInRow PRIVATE cxx_std_17)

# find all libraries within SFML/lib and assign them to SFML variable
find_library(SFML NAMES sfml-system sfml-window sfml-graphics PATHS ${CMAKE_SOURCE_DIR}/dependencies/SFML/lib)

# check if SFML is found
if(NOT SFML)
  message(FATAL_ERROR "SFML library not found")
endif()

# link SFML to the project
target_link_libraries(ThreeInRow ${SFML})

# have to be present to make VisualStudio run the executable after build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ThreeInRow)