cmake_minimum_required(VERSION 3.8)

project(unit_tests CXX)

# Load common cmake
include(${PROJECT_SOURCE_DIR}/../cmake/CppReflectionCommon.cmake)

# Find required packages
find_package(GTest CONFIG REQUIRED)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

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

add_executable(unit_tests ${SOURCES})

set_target_properties(unit_tests
	PROPERTIES
	CXX_STANDARD 11
)

target_link_libraries(unit_tests PRIVATE
	CppReflection
	GTest::gtest
	GTest::gtest_main
)
