cmake_minimum_required(VERSION 3.11 FATAL_ERROR)


project(csim_project VERSION 0.1 DESCRIPTION "c libraries" LANGUAGES C CXX)

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

file(GLOB CSIM_SRC
	"src/*.cpp"
	"src/*.c"
	)

add_library(csim ${CSIM_SRC})
include(FetchContent)
if(NOT TARGET Eigen3::Eigen)
	find_package(Eigen3 3.3 CONFIG QUIET)
	if(NOT Eigen3_FOUND)
		message(STATUS "Eigen3 was not found. Downloading")
		FetchContent_Declare(
			Eigen
			GIT_REPOSITORY git@gitlab.com:libeigen/eigen.git
			GIT_TAG master
			GIT_SHALLOW TRUE
			GIT_PROGRESS TRUE)
		set(EIGEN_BUILD_DOC OFF)
		set(BUILD_TESTING OFF)
		set(EIGEN_BUILD_PKGCONFIG OFF)
		set( OFF)
		FetchContent_MakeAvailable(Eigen)
	else()
		message(STATUS "Eigen FOUND in ${Eigen3_DIR}")
	endif(NOT Eigen3_FOUND)
endif(NOT TARGET Eigen3::Eigen)
target_link_libraries(csim PUBLIC  Eigen3::Eigen)


if(OPENMP_CXX_FOUND)
	message(STATUS "OpenMP support found")
	target_link_libraries(csim PRIVATE OpenMP::OpenMP_CXX)
endif(OPENMP_CXX_FOUND)


target_include_directories(csim PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/csim>
	"$<INSTALL_INTERFACE:include/csim>")
target_include_directories(csim INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	"$<INSTALL_INTERFACE:include>")
install(TARGETS csim EXPORT cppsimTargets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)


