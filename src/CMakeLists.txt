file(GLOB SOURCES_APP "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES_APP} ${VERSION_H_FILE})

target_link_libraries(${PROJECT_NAME} pthread ${CONAN_LIBS})
