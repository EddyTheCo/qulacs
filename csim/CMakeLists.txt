cmake_minimum_required(VERSION 3.11 FATAL_ERROR)



project(csim VERSION 0.1 DESCRIPTION "c libraries?" LANGUAGES C CXX)

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

add_library(${PROJECT_NAME} ${CSIM_SRC})

find_package (Eigen3 3.3  NO_MODULE REQUIRED)
if(OPENMP_CXX_FOUND)
	message(STATUS "OpenMP support found")
	target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)
endif(OPENMP_CXX_FOUND)

target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)

target_include_directories(${PROJECT_NAME} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/csim>
	"$<INSTALL_INTERFACE:include/csim>")
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	"$<INSTALL_INTERFACE:include>")
install(TARGETS ${PROJECT_NAME} EXPORT cppsimTargets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)


