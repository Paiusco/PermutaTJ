add_library (SOURCES_N_HEADERS
  person.cpp
  person.h
  exchangetj.cpp
  exchangetj.h)

add_executable(${PROJECT_NAME} main.cpp ${VERSION_H_FILE})

# find_library()
target_link_libraries(${PROJECT_NAME} PRIVATE SOURCES_N_HEADERS ${CONAN_LIBS})
