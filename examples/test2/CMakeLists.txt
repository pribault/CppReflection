cmake_minimum_required(VERSION 3.8)

project(test2 CXX)

# Load common cmake
include(${PROJECT_SOURCE_DIR}/../../cmake/CppReflectionCommon.cmake)

# Set environment
cppreflection_set_env()

set(CPPREFLECTION_BINARY_DIR ${CPPREFLECTION_ROOT_DIR}/build/bin)

cppreflection_set(INCLUDE_DIR ${PROJECT_SOURCE_DIR})
cppreflection_set(SOURCE_DIR ${PROJECT_SOURCE_DIR})
cppreflection_set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES RELATIVE
	"${CMAKE_CURRENT_SOURCE_DIR}"
	${INCLUDE_DIR}/**.h
	${INCLUDE_DIR}/**.inl
	${SOURCE_DIR}/**.cpp
)

include_directories(
	${INCLUDE_DIR}
	${CPPREFLECTION_INCLUDE_DIR}
)

add_executable(test2 ${SOURCES})

target_link_libraries(test2 PRIVATE
	CppReflection
)
