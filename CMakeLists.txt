cmake_minimum_required (VERSION 2.8.11)
project(pool)

if (DEFINED ENV{WAZN_DIR})
    get_filename_component(WAZN_DIR $ENV{WAZN_DIR} ABSOLUTE)
    message("Using WAZN source from env ${WAZN_DIR}")
else()
    get_filename_component(WAZN_DIR "${CMAKE_SOURCE_DIR}/../wazn" ABSOLUTE)
    message("WAZN source directory is not defined, using default ${WAZN_DIR}")
endif()

add_subdirectory(hashing)
add_subdirectory(cnutil)

add_custom_command(
    OUTPUT build/bin
    COMMAND build/env.sh go get -v ./...
)

add_custom_target(build ALL DEPENDS hashing cnutil ${CMAKE_CURRENT_BINARY_DIR}/build/bin)
