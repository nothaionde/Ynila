cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (Ynila)

# Adding a preprocessor directive to suppress warnings
add_definitions(-D_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)


file(GLOB Ynila_SRC
	"src/*.h" 
	"src/*.cpp"
	"src/Engine/Core/*.h" 
	"src/Engine/Core/*.cpp" 
	"src/Engine/Graphics/*.h" 
	"src/Engine/Graphics/*.cpp" 
	"src/Engine/Graphics/OpenGL/*.h" 
	"src/Engine/Graphics/OpenGL/*.cpp" 
	"src/Engine/Graphics/GUI/*.h" 
	"src/Engine/Graphics/GUI/*.cpp" 
	"src/Engine/Scene/*.h" 
	"src/Engine/Scene/*.cpp" 
	"src/Sandbox/*.h" 
	"src/Sandbox/*.cpp"
	)
add_executable (${PROJECT_NAME} 
	${Ynila_SRC}
		)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/bin"
)

target_include_directories ( ${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	)

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ynila PROPERTY CXX_STANDARD 20)
endif()

