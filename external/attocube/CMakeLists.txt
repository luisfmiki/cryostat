cmake_minimum_required(VERSION 3.6)


if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to Release as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE
        STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# This is how we could set compiler options
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -Werror")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDLL_EXPORT")
endif()

set(LIBRARY_SRC
    net.cpp
    net.h
    cJSON.cpp
    cJSON.h
    attocubeJSONCall.cpp
    attocubeJSONCall.h
    attoDry.h)

if(WIN32)
    list(APPEND LIBS_TO_LINK wsock32 ws2_32)
endif()

add_library(
    attolib STATIC
    "${LIBRARY_SRC}"
    )

target_link_libraries(attolib ${LIBS_TO_LINK} libattoDry-1.0.0.dll)


