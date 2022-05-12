## Sets the project variables ##
cmake_minimum_required(VERSION 3.16.3)
EXECUTE_PROCESS (COMMAND getconf LONG_BIT COMMAND tr -d '\n' OUTPUT_VARIABLE ARCH)
EXECUTE_PROCESS (COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE PCT)
if (${PCT} STREQUAL "x86_64")
	set (ARCHITECTURE "amd64")
elseif(${PCT} STREQUAL "i386")
	set (ARCHITECTURE "i386")
elseif(${PCT} STREQUAL "arm")
	set (ARCHITECTURE "arm${ARCH}")
else()
	message(FATAL_ERROR "Unknown Architecture type.")
endif()
message(STATUS "Detected architecture: ${ARCHITECTURE}")
project (libmount-cpp VERSION 0.2)
set (CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ECLIPSE_VERSION 4.23.0)

# Adds options

# CPack variables
set (CPACK_GENERATOR "TGZ" "DEB" "RPM")
set (CMAKE_PROJECT_HOMEPAGE_URLE "https://github.com/proatgram/libmount-cpp")
set (CPACK_PACKAGE_DESCRIPTION "A library for C++ that adds mounting filesystems")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY ${CPACK_PACKAGE_DESCRIPTION})
set (CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set (CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set (CPACK_DEBIAN_PACKAGE_ARCHITECTURE "${ARCHITECTURE}")
set (CPACK_PACKAGE_CONTACT "tgh6407@gmail.com")
set (CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE)
set (CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/README.md)
set (CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set (CPACK_RPM_PACKAGE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE)
set (CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${ARCHITECTURE})
set (CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set (CPACK_SOURCE_IGNORE_FILES "build/;/build/;//.git;.git;deps/;")
set (CPACK_DEBIAN_PACKAGE_DEPENDS "libstdc++6 (>= 10.3.0-1ubuntu1~20.04), libc6 (>= 2.31-0ubuntu9.7), libgcc1 (>= 1:10.3.0-1ubuntu1~20.04)")


# Sets dependancy git repository information

### NO DEPENDANCIES ###

# Finds needed libraries

## Configures dependancies ##

## Configures targets ##
file (GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.c")
file (GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/include/*.inl")

file(GLOB_RECURSE MANDATA "${CMAKE_SOURCE_DIR}/docs/doxygen/man/man3/*")
file(GLOB_RECURSE DOCDATA "${CMAKE_SOURCE_DIR}/docs/doxygen/html/*")

add_library (mount-cpp SHARED ${SOURCES} ${HEADERS})
target_include_directories(mount-cpp PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(mount-cpp PROPERTIES VERSION ${CMAKE_PROJECT_VERSION} SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR} PUBLIC_HEADER ${HEADERS})
target_compile_options(mount-cpp PUBLIC "-std=c++17")

# Sets up Doxygen
find_package(Doxygen REQUIRED dot)
message(STATUS "Doxygen found!")
set(DOXYGEN_EXCLUDE_PATTERNS "build/")
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs/doxygen)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN YES)
doxygen_add_docs(docs ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src ALL WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

## Adds installation instructions ##
install (TARGETS mount-cpp LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (FILES ${MANDATA} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/man/man3)
install (FILES ${DOCDATA} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/doc/libmount-cpp)
# Includes
include(GNUInstallDirs)
include(CPack)
include(FindDoxygen)