include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Catch2 REQUIRED)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)

catch_discover_tests(tests)