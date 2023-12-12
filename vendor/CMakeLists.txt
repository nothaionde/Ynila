add_subdirectory(spdlog)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE spdlog)

target_include_directories(vendor INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include
        )