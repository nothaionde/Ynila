add_subdirectory(spdlog)
add_subdirectory(glfw)
add_subdirectory(glad)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE spdlog)
target_link_libraries(vendor INTERFACE glfw)
target_link_libraries(vendor INTERFACE glad)

target_include_directories(vendor INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
        )