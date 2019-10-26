add_library(exchangetj STATIC ./src/exchangetj.cpp)

set_target_properties(exchangetj PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

target_include_directories(exchangetj PUBLIC ./include)
