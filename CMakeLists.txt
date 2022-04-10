cmake_minimum_required(VERSION 3.13)

#########################
# Configuration Options #
#########################

project(posu LANGUAGES CXX VERSION 0.0.1)

option(POSU_ENABLE_WALL                          OFF)
option(POSU_ENABLE_WERROR                        OFF)
option(POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS OFF)
option(POSU_ENABLE_TESTING                       OFF)
option(POSU_ENABLE_STATIC_STDLIB                 OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(DEFINED POSU_STDLIB AND NOT POSU_STDLIB STREQUAL "default")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=${POSU_STDLIB}")
    else()
        message(FATAL_ERROR "POSU_STDLIB must be \"default\" unless using Clang")
    endif()
endif()

if(DEFINED POSU_STDLIB_PATH AND EXISTS ${POSU_STDLIB_PATH})
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L ${POSU_STDLIB_PATH}")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -rpath ${POSU_STDLIB_PATH}")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-rpath -Wl,${POSU_STDLIB_PATH}")
    else()
        message(SEND_ERROR  "option  : POSU_STDLIB_PATH")
        message(SEND_ERROR  "compiler: ${CMAKE_CXX_COMPILER_ID}")
        message(FATAL_ERROR "setting the Standard Library link path on this compiler unsupported")
    endif()
endif()

if(DEFINED POSU_STDLIB_INCLUDE AND EXISTS ${POSU_STDLIB_INCLUDE})
    if(
        CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
    )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem ${POSU_STDLIB_INCLUDE}")
    else()
        message(SEND_ERROR  "option  : POSU_STDLIB_INCLUDE")
        message(SEND_ERROR  "compiler: ${CMAKE_CXX_COMPILER_ID}")
        message(FATAL_ERROR "setting the Standard Library link path on this compiler unsupported")
    endif()
endif()

if(POSU_ENABLE_STATIC_STDLIB)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
    else()
        message(FATAL_ERROR "POSU_ENABLE_STATIC_STDLIB must be \"OFF\" unless using Clang")
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
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts-diagnostics-depth=9")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-backtrace-limit=0")
    endif()
else()
    if(POSU_ENABLE_DETAILED_CONCEPTS_DIAGNOSTICS)
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
    POSU_META_HPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/meta/algorithm.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/meta/list.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/meta/ratio.hpp
)
set(
    POSU_META_IPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/meta/ipp/algorithm.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/meta/ipp/list.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/meta/ipp/ratio.ipp
)
set(
    POSU_META_TEST_CPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/test/meta/test_list.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/meta/test_meta.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/meta/test_ratio.cpp
)

set(
    POSU_UNITS_HPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/base_unit.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/derived_unit.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/dimension.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/kind.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/unit_of_measure.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/units.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/acceleration.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/amount_of_substance.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/angle.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/electric_charge.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/electric_current.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/energy.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/force.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/frequency.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/length.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/luminous_flux.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/luminous_intensity.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/mass.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/power.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/solid_angle.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/thermodynamic_temperature.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/time.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/velocity.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/amount_of_substance.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/angle.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/defining_constants.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/electric_charge.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/electric_current.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/energy.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/force.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/frequency.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/length.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/luminous_flux.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/luminous_intensity.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/mass.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/power.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/time.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/solid_angle.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/thermodynamic_temperature.hpp
)
set(
    POSU_UNITS_IPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/ipp/base_unit.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/ipp/derived_unit.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/ipp/dimension.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/ipp/kind.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/ipp/unit_of_measure.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/amount_of_substance.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/angle.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/electric_charge.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/electric_current.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/energy.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/force.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/frequency.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/length.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/luminous_intensity.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/luminous_flux.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/mass.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/power.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/solid_angle.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/speed.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/thermodynamic_temperature.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/units/system/si/ipp/time.ipp
)
set(
    POSU_UNITS_TEST_CPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/test/units/test_base_unit.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/test_units.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_acceleration.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_amount_of_substance.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_angle.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_defining_constants.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_electric_charge.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_electric_current.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_energy.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_force.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_frequency.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_length.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_luminous_flux.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_luminous_intensity.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_mass.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_power.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_solid_angle.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_speed.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_thermodynamic_temperature.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/units/system/si/test_time.cpp
)

set(
    POSU_HPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/concepts.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ratio.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/string_literal.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/utility.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/vmath.hpp
        ${CMAKE_CURRENT_LIST_DIR}/posu/zip_range.hpp
)
set(
    POSU_IPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/ratio.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/utility.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/vmath.ipp
        ${CMAKE_CURRENT_LIST_DIR}/posu/ipp/zip_range.ipp
)
set(
    POSU_TEST_CPP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/test/test_arith_tuple.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/test_concepts.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/test_posu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/test_ratio.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/test_string_literal.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test/test_zip_range.cpp
)

set(
    POSU_ALL_HPP_FILES
        ${POSU_META_HPP_FILES}
        ${POSU_UNITS_HPP_FILES}
        ${POSU_HPP_FILES}
)
set(
    POSU_ALL_IPP_FILES
        ${POSU_META_IPP_FILES}
        ${POSU_UNITS_IPP_FILES}
        ${POSU_IPP_FILES}
)
set(
    POSU_ALL_CPP_FILES
        ${POSU_META_TEST_CPP_FILES}
        ${POSU_UNITS_TEST_CPP_FILES}
        ${POSU_TEST_CPP_FILES}
)

##################
# Declare Target #
##################

add_library(posu INTERFACE)
target_include_directories(posu INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(posu INTERFACE ${POSU_HPP_FILES})

if(BUILD_TESTING AND POSU_ENABLE_TESTING)
    find_package(Catch2 REQUIRED)

    add_executable(test_posu ${POSU_TEST_CPP_FILES})
    target_link_libraries(test_posu PRIVATE Catch2::Catch2)
    target_link_libraries(test_posu PRIVATE posu)
    add_test(NAME test_posu COMMAND test_posu)

    add_executable(test_units ${POSU_UNITS_TEST_CPP_FILES})
    target_link_libraries(test_units PRIVATE Catch2::Catch2)
    target_link_libraries(test_units PRIVATE posu)
    add_test(NAME test_units COMMAND test_units)

    add_executable(test_meta ${POSU_META_TEST_CPP_FILES})
    target_link_libraries(test_meta PRIVATE Catch2::Catch2)
    target_link_libraries(test_meta PRIVATE posu)
    add_test(NAME test_meta COMMAND test_meta)
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
                    ${POSU_ALL_HPP_FILES}
                    ${POSU_ALL_IPP_FILES}
                    ${POSU_ALL_CPP_FILES}
            DEPENDS
                ${POSU_ALL_HPP_FILES}
                ${POSU_ALL_IPP_FILES}
                ${POSU_ALL_CPP_FILES}
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
                    ${POSU_ALL_CPP_FILES}
            DEPENDS
                ${POSU_ALL_HPP_FILES}
                ${POSU_ALL_IPP_FILES}
                ${POSU_ALL_CPP_FILES}
    )
else()
    message(STATUS "clang-tidy not found")
endif()
