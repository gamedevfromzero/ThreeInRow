cmake_minimum_required(VERSION 3.28)

project(CMakeSFMLProject LANGUAGES CXX)

add_executable(main src/threeinrow/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

add_subdirectory(dependencies/SFML)
link_directories(dependencies/SFML/extlib)
target_link_libraries(main PRIVATE SFML::Graphics SFML::System SFML::Window)