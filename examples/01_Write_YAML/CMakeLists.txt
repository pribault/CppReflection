cmake_minimum_required(VERSION 3.8)

project(01_Write_YAML CXX)

# Load common cmake
include(${PROJECT_SOURCE_DIR}/../../cmake/CppReflectionCommon.cmake)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR})
set(SOURCE_DIR ${PROJECT_SOURCE_DIR})

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

add_executable(01_Write_YAML ${SOURCES})

set_target_properties(01_Write_YAML
	PROPERTIES
	CXX_STANDARD 11
)

target_link_libraries(01_Write_YAML PRIVATE
	CppReflection
)
