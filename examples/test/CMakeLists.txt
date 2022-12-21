cmake_minimum_required(VERSION 3.8)

project(test CXX)

# Load common cmake
include(${PROJECT_SOURCE_DIR}/../../cmake/CppReflectionCommon.cmake)

set(CPPREFLECTION_BINARY_DIR ${CPPREFLECTION_ROOT_DIR}/build/bin)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR})
set(SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

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

add_executable(test ${SOURCES})

target_link_libraries(test PRIVATE
	CppReflection
)
