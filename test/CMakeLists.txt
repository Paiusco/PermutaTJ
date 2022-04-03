include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

add_executable(tests
  catch_main.cpp 
  person_test.cpp 
  match_seeker_test.cpp)

find_package(Catch2 REQUIRED)
target_link_libraries(tests PRIVATE SOURCES_N_HEADERS Catch2::Catch2)

include(CTest)
include(Catch)

catch_discover_tests(tests)