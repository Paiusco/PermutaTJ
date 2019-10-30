add_library(exchangetj STATIC exchangetj.cpp)
add_executable(main main.cpp)

set_target_properties(exchangetj PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
set_target_properties(main PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

target_include_directories(exchangetj PUBLIC "./" "../include")

target_link_libraries(main exchangetj)
target_link_libraries(main atomic)
