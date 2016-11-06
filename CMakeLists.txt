##################
# Initialization #
##################
# Project name is not mandatory, but you should use it
project(DS)

# States that CMake required version must be >= 2.6
cmake_minimum_required(VERSION 2.6)

#####################
# Setup Environment #
#####################
# set to include custom modules
set(CMAKE_MODULE_PATH $ENV{CMAKE_MODULE_PATH} ${DS_SOURCE_DIR}/cmake)

# set build type if specified by environment
if((NOT CMAKE_BUILD_TYPE) AND (NOT $ENV{CMAKE_BUILD_TYPE} STREQUAL ""))
    set(CMAKE_BUILD_TYPE $ENV{CMAKE_BUILD_TYPE})
endif()

# Set include directories
include_directories(${DS_SOURCE_DIR}/include)

# Get CPP files
file(GLOB SRC ${DS_SOURCE_DIR}/src/*cpp)

# Get executable files
file(GLOB EXECLIST ${DS_SOURCE_DIR}/bin/*cpp)


###############
# C++ Options #
###############
# Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# determine build type based on directory name. Do not allow for in source building
#
if(${DS_SOURCE_DIR} STREQUAL ${DS_BINARY_DIR})
  message(FATAL_ERROR " *** In-source building not allowed. Please create a subdir 'Release' or 'Debug', and run cmake from within this directory 'cmake ..' ***")
else()
  get_filename_component(TYPE ${DS_BINARY_DIR} NAME)
  string(TOUPPER "${TYPE}" TYPE)
  if(${TYPE} STREQUAL "RELEASE")
    set(CMAKE_BUILD_TYPE Release)
  else()
    set(CMAKE_BUILD_TYPE Debug)
 endif()
 message("-- Build type set to: ${TYPE}")
endif()

#######################
# Set Compile Targets #
#######################
# src libraries
if(NOT SRC STREQUAL "")
  set(LIBNAME "DS_core")
  add_library(${LIBNAME} ${SRC})
endif()

# executables
foreach(EXEC ${EXECLIST})
  get_filename_component(EXECNAME ${EXEC} NAME_WE)
  add_executable(${EXECNAME} ${EXEC})

  if(NOT SRC STREQUAL "")
    target_link_libraries(${EXECNAME} LINK_PUBLIC ${LIBNAME})
  endif()

  message("-- Adding executable: ${EXECNAME}")
endforeach(EXEC)
