
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)



project(qulacs VERSION 0.1 DESCRIPTION "qulacs c++ libraries" LANGUAGES CXX)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
		STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_EXTENSIONS OFF)




add_subdirectory(csim)

if(USE_GPU)
	add_subdirectory(gpusim)
endif(USE_GPU)


add_subdirectory(cppsim)


