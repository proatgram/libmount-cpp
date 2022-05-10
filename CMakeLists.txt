# Includes
include(CPack)
include(GNUInstallDirs)
## Sets the project variables ##
cmake_minimum_required(VERSION 3.16)
EXECUTE_PROCESS (COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)

project (libmount-cpp VERSION 0.1)
set (CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ECLIPSE_VERSION 4.23.0)
# CPack variables
set (CPACK_GENERATOR "TGZ" "DEB" "RPM")
set (CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set (CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set (CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${ARCHITECTURE})
set (CPACK_PACKAGE_CONTACT "tgh6407@gmail.com")
set (CPACK_DEBIAN_PACKAGE_MAINTAINER "Timothy Hutchins")
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE")
set (CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set (CPACK_DEBIAN_FILE_NAME "${DEB-DEFAULT}")
set (CPACK_PACKAGE_NAME ${PROJECT_NAME})
set (CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set (CPACK_SOURCE_IGNORE_FILES "build/;/build/;//.git;.git;deps/;")

# Sets dependancy git repository information

# Finds needed libraries

## Configures dependancies ##

## Configures targets ##
file (GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.c")
file (GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/include/*.inl")

add_library (libmount-cpp SHARED ${SOURCES} ${HEADERS})
target_include_directories(libmount-cpp PUBLIC ${CMAKE_SOURCE_DIR}/include)
set_target_properties(libmount-cpp PROPERTIES VERSION ${CMAKE_PROJECT_VERSION} SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR})
target_compile_options(libmount-cpp PUBLIC "-std=c++17")

## Adds installation instructions ##
install (TARGETS libmount-cpp LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT applications PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
