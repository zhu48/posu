cmake_minimum_required(VERSION 3.13)

#########################
# Configuration Options #
#########################

project(posu LANGUAGES CXX VERSION 0.0.1)

option(POSU_ENABLE_WALL                          OFF)
option(POSU_ENABLE_WERROR                        OFF)
option(POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS OFF)
option(POSU_ENABLE_TESTING                       OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(DEFINED POSU_STDLIB AND NOT POSU_STDLIB STREQUAL "default")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=${POSU_STDLIB}")
    else()
        message(FATAL_ERROR "POSU_STDLIB must be \"default\" unless using Clang")
    endif()
endif()

# zip-range only standards-compliant with C++20 iterator rework
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()
if(CMAKE_CXX_STANDARD LESS 20)
    message(FATAL_ERROR "This library requires C++20")
endif()

# handle enable-all-warnings
if(POSU_ENABLE_WALL)
    if(
        CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
    )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    else()
        message(SEND_ERROR  "option  : POSU_ENABLE_WALL")
        message(SEND_ERROR  "compiler: ${CMAKE_CXX_COMPILER_ID}")
        message(FATAL_ERROR "enabling all warning on this compiler unsupported")
    endif()
endif()

# handle treat-warnings-as-errors
if(POSU_ENABLE_WERROR)
    if(
        CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
    )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
    else()
        message(SEND_ERROR  "option  : POSU_ENABLE_WERROR")
        message(SEND_ERROR  "compiler: ${CMAKE_CXX_COMPILER_ID}")
        message(FATAL_ERROR "warnings as errors on this compiler unsupported")
    endif()
endif()

# handle detailed-concepts-diagnostics
if(POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts-diagnostics-depth=9")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(STATUS "ignoring POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS on clang")
    else()
        message(SEND_ERROR  "option  : POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS")
        message(SEND_ERROR  "compiler: ${CMAKE_CXX_COMPILER_ID}")
        message(FATAL_ERROR "concepts diagnostics on this compiler unsupported")
    endif()
endif()

#######################
# Gather Dependencies #
#######################

include(CTest)

find_program(POSU_CLANG_FORMAT clang-format)
find_program(POSU_CLANG_TIDY   clang-tidy)

##################
# Gather Sources #
##################

set(
    POSU_HPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/concepts.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/type_list.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/type_ratio.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/utility.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/vmath.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/zip_range.hpp
)
set(
    POSU_IPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/type_list.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/type_ratio.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/utility.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/vmath.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/zip_range.ipp
)

##################
# Declare Target #
##################

add_library(posu INTERFACE)
target_include_directories(posu INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(posu INTERFACE ${POSU_HPP_FILES})

if(BUILD_TESTING AND POSU_ENABLE_TESTING)
    find_package(Catch2 REQUIRED)

    add_executable(test_arith_tuple ${CMAKE_CURRENT_LIST_DIR}/test/test_arith_tuple.cpp)
    target_link_libraries(test_arith_tuple PRIVATE Catch2::Catch2)
    target_link_libraries(test_arith_tuple PRIVATE posu)
    add_test(NAME test_arith_tuple COMMAND test_arith_tuple)

    add_executable(test_concepts ${CMAKE_CURRENT_LIST_DIR}/test/test_concepts.cpp)
    target_link_libraries(test_concepts PRIVATE Catch2::Catch2)
    target_link_libraries(test_concepts PRIVATE posu)
    add_test(NAME test_concepts COMMAND test_concepts)

    add_executable(test_zip_range ${CMAKE_CURRENT_LIST_DIR}/test/test_zip_range.cpp)
    target_link_libraries(test_zip_range PRIVATE Catch2::Catch2)
    target_link_libraries(test_zip_range PRIVATE posu)
    add_test(NAME test_zip_range COMMAND test_zip_range)
    set_tests_properties(test_zip_range PROPERTIES DEPENDS test_arith_tuple)

    add_executable(test_type_list ${CMAKE_CURRENT_LIST_DIR}/test/test_type_list.cpp)
    target_link_libraries(test_type_list PRIVATE Catch2::Catch2)
    target_link_libraries(test_type_list PRIVATE posu)
    add_test(NAME test_type_list COMMAND test_type_list)
    set_tests_properties(test_type_list PROPERTIES DEPENDS test_arith_tuple)

    add_executable(test_type_ratio ${CMAKE_CURRENT_LIST_DIR}/test/test_type_ratio.cpp)
    target_link_libraries(test_type_ratio PRIVATE Catch2::Catch2)
    target_link_libraries(test_type_ratio PRIVATE posu)
    add_test(NAME test_type_ratio COMMAND test_type_ratio)
    set_tests_properties(test_type_ratio PROPERTIES DEPENDS test_arith_tuple)
endif()

################
# Clang-Format #
################

if(POSU_CLANG_FORMAT)
    message(STATUS "generating target clang_format")

    add_custom_target(
        clang_format
            COMMAND
                ${POSU_CLANG_FORMAT} -i
                    ${POSU_HPP_FILES}
                    ${POSU_IPP_FILES}
                    ${CMAKE_CURRENT_LIST_DIR}/test/test_arith_tuple.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/test/test_type_list.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/test/test_zip_range.cpp
            DEPENDS
                ${POSU_HPP_FILES}
                ${POSU_IPP_FILES}
                ${POSU_UNITS_TEST_CPP_FILES}
    )
else()
    message(STATUS "clang-format not found")
endif()

##############
# Clang-Tidy #
##############

if(POSU_CLANG_TIDY)
    message(STATUS "generating target clang_tidy")

    add_custom_target(
        clang_tidy
            COMMAND
                ${POSU_CLANG_TIDY}
                    -p ${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_LIST_DIR}/test/test_arith_tuple.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/test/test_type_list.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/test/test_zip_range.cpp
            DEPENDS
                ${POSU_HPP_FILES}
                ${POSU_IPP_FILES}
                ${CMAKE_CURRENT_LIST_DIR}/test/test_arith_tuple.cpp
                ${CMAKE_CURRENT_LIST_DIR}/test/test_zip_range.cpp
    )
else()
    message(STATUS "clang-tidy not found")
endif()
