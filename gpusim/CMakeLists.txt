

cmake_minimum_required(VERSION 3.11 FATAL_ERROR)



project(gpusim VERSION 0.1 DESCRIPTION "gpu libraries" LANGUAGES CUDA)

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

file(GLOB GPUSIM_SRC
	"src/*.cu"
	)

add_library(${PROJECT_NAME} ${GPUSIM_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE -lcublas -lcurand)
target_include_directories(${PROJECT_NAME} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gpusim>
	"$<INSTALL_INTERFACE:/include/gpusim>")
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	"$<INSTALL_INTERFACE:include>")
install(TARGETS ${PROJECT_NAME} EXPORT cppsimTargets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)
