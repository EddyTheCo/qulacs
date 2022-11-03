
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(cppsim_project VERSION 0.1 DESCRIPTION "cpp libraries" LANGUAGES CXX)

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

file(GLOB CPPSIM_SRC
	"src/*.cpp"
	)

add_library(cppsim ${CPPSIM_SRC})

include(FindOpenMP)
if(OPENMP_CXX_FOUND)
	message(STATUS "OpenMP support found")
	target_link_libraries(cppsim PRIVATE OpenMP::OpenMP_CXX)
endif(OPENMP_CXX_FOUND)

if(USE_GPU)
	target_compile_definitions(cppsim PRIVATE _USE_GPU)
endif(USE_GPU)

if(USE_GPU)
	target_link_libraries(cppsim PUBLIC csim gpusim)
else()
	target_link_libraries(cppsim PUBLIC csim )
endif(USE_GPU)

target_include_directories(cppsim PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/cppsim>
	"$<INSTALL_INTERFACE:include/cppsim>")
target_include_directories(cppsim INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
	"$<INSTALL_INTERFACE:include>")

install(TARGETS cppsim EXPORT cppsimTargets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)
install(EXPORT cppsimTargets
	FILE cppsimTargets.cmake
	NAMESPACE qulacs::
	DESTINATION lib/cmake/cppsim
	)
include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/cppsimConfig.cmake"
	INSTALL_DESTINATION "lib/cmake/cppsim"
	NO_SET_AND_CHECK_MACRO
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
	)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/cppsimConfigVersion.cmake"
	VERSION "0.1.1.0"
	COMPATIBILITY AnyNewerVersion
	)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/cppsimConfig.cmake
	${CMAKE_CURRENT_BINARY_DIR}/cppsimConfigVersion.cmake
	DESTINATION lib/cmake/cppsim
	)
export(EXPORT cppsimTargets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/cppsimTargets.cmake"
	)
