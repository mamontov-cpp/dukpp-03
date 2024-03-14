cmake_minimum_required(VERSION 2.8.12)
project(dukpp03-tests)

file(GLOB_RECURSE HDRS ../include/*.h)

# set(Boost_DEBUG 1)
find_package(Boost REQUIRED timer chrono system)

set(DUKPP03_EXECUTABLE_NAME "dukpp-03-tests")
set(DUKPP03_LINKABLE_NAME "dukpp-03")

if (NOT CMAKE_BUILD_TYPE)
	message(STATUS "No build type selected, default to Release")
	set(CMAKE_BUILD_TYPE "Release")
	set(DUKPP03_LINKABLE_NAME "${DUKPP03_LIBRARY_NAME}-release")
else()	
	string(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOWERCASED)
	set(DUKPP03_LINKABLE_NAME "dukpp-03-${CMAKE_BUILD_TYPE_LOWERCASED}")
endif()

include_directories(../../include)
include_directories(${Boost_INCLUDE_DIRS})

link_directories("../../lib" ${Boost_LIBRARY_DIRS})

set(SRCS "main.cpp" "context.cpp" "callables.cpp" "point.cpp" "jsobject.cpp")


add_executable(${DUKPP03_EXECUTABLE_NAME} ${SRCS} ${HDRS})

target_link_libraries(${DUKPP03_EXECUTABLE_NAME} ${DUKPP03_LINKABLE_NAME} ${Boost_LIBRARIES})

set_target_properties(${DUKPP03_EXECUTABLE_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "../../lib"
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "../../lib"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "../../lib"
    LIBRARY_OUTPUT_DIRECTORY "../../lib"
	LIBRARY_OUTPUT_DIRECTORY_DEBUG "../../lib"
	LIBRARY_OUTPUT_DIRECTORY_RELEASE "../lib"
    RUNTIME_OUTPUT_DIRECTORY "../../bin"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "../../bin"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "../../bin"
	DEBUG_POSTFIX "-debug"
	RELEASE_POSTFIX "-release"
)
