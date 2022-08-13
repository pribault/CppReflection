
macro(cppreflection_set)
	set(${ARGV0} ${ARGV1} PARENT_SCOPE)
	set(${ARGV0} ${ARGV1})
endmacro()

# setup cmake env
function(cppreflection_set_env)
	# CPPREFLECTION_CMAKE_DIR is the directory of RxCWCommon.cmake
	cppreflection_set(CPPREFLECTION_CMAKE_DIR ${CMAKE_CURRENT_FUNCTION_LIST_DIR})

	cppreflection_set(CPPREFLECTION_ROOT_DIR ${CPPREFLECTION_CMAKE_DIR}/..)
	cppreflection_set(CPPREFLECTION_INCLUDE_DIR ${CPPREFLECTION_ROOT_DIR}/include)
	cppreflection_set(CPPREFLECTION_SOURCE_DIR ${CPPREFLECTION_ROOT_DIR}/src)
	cppreflection_set(CPPREFLECTION_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

	cppreflection_set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CPPREFLECTION_OUTPUT_DIR})
	cppreflection_set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CPPREFLECTION_OUTPUT_DIR})
	cppreflection_set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CPPREFLECTION_OUTPUT_DIR})
endfunction()
