cmake_minimum_required(VERSION 2.8)

project(exchangetj)
set(APP_NAME ${PROJECT_NAME})

set(PROJECT_DESCRIPTION "Example Daemon")

# Enable C++11 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# add source folder!
add_subdirectory(src)

# add config directory
#add_subdirectory(conf)

# include docs
#add_subdirectory(doc)

# GTest UnitTests
#add_subdirectory(test EXCLUDE_FROM_ALL)