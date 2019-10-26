file(GLOB SOURCES_APP "*.cpp")

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(${APP_NAME} ${SOURCES_APP} ${VERSION_H_FILE})

target_link_libraries(${APP_NAME} pthread)