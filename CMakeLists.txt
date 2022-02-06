cmake_minimum_required(VERSION 3.22)

project(Exchangetj VERSION 1.0)

set(PROJECT_DESCRIPTION "PermutaTJ")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)  # Includes the contents of the conanbuildinfo.cmake file.
conan_basic_setup()  # Prepares the CMakeList.txt for Conan.

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Werror -Wextra -Wshadow -Wpedantic)

find_program(CPPCHECK cppcheck)
# Enable all warnings that are actionable by the user of this toolset
# style should enable the other 3, but we'll be explicit just in case
set(CMAKE_CXX_CPPCHECK
    ${CPPCHECK}
    --enable=style,performance,warning,portability
    --force
    --inline-suppr
    # We cannot act on a bug/missing feature of cppcheck
    --suppress=internalAstError
    # if a file does not have an internalAstError, we get an unmatchedSuppression error
    --suppress=unmatchedSuppressionv
    --suppress=cppcheckError:*cereal*
    --inconclusive)
if(NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
  set(CMAKE_CXX_CPPCHECK ${CMAKE_CXX_CPPCHECK} --std=c++${CMAKE_CXX_STANDARD})
endif()

enable_testing()

# add source folder!
add_subdirectory(src)

# include docs
#add_subdirectory(doc)

# GTest UnitTests
add_subdirectory(test)
