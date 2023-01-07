cmake_minimum_required(VERSION 3.8)

project(CppReflection CXX)

# Options
if(NOT DEFINED ENABLE_DYNAMIC_LINK)
	set(ENABLE_DYNAMIC_LINK True)
endif()

if(ENABLE_DYNAMIC_LINK)
	if(MSVC)
		set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
		set(BUILD_SHARED_LIBS TRUE)
	endif()
endif()

# Load common cmake
include(${PROJECT_SOURCE_DIR}/cmake/CppReflectionCommon.cmake)

add_subdirectory(examples)
add_subdirectory(tests)

# Find required packages
find_package(yaml-cpp CONFIG REQUIRED)

# Retrieve sources
file(GLOB_RECURSE SOURCES RELATIVE
	"${CMAKE_CURRENT_SOURCE_DIR}"
	${CPPREFLECTION_INCLUDE_DIR}/**.h
	${CPPREFLECTION_INCLUDE_DIR}/**.inl
	${CPPREFLECTION_SOURCE_DIR}/**.cpp
)

include_directories(
	${CPPREFLECTION_INCLUDE_DIR}
)

# Create library
if(ENABLE_DYNAMIC_LINK)
	add_library(CppReflection SHARED ${SOURCES})
else()
	add_library(CppReflection STATIC ${SOURCES})
endif()

set_target_properties(CppReflection
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CPPREFLECTION_OUTPUT_DIR}
)

target_link_libraries(CppReflection PRIVATE
	yaml-cpp
)

target_compile_features(CppReflection PRIVATE cxx_std_17)
