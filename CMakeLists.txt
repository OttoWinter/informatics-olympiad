cmake_minimum_required(VERSION 3.8)
project(informatics-olympiad)

set(CMAKE_CXX_STANDARD 11)

function(setup_project)
    get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    string(REPLACE " " "_" ProjectId ${ProjectId})
    set(NAME ${ProjectId})
    file(GLOB SOURCE_FILES
            "*.h"
            "*.cpp")

    project(${NAME})
    add_executable(${NAME} ${SOURCE_FILES})

    file(GLOB SAMPLE_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/"
            "*.py"
            "*.in.*"
            "*.out.*")

    foreach(f ${SAMPLE_FILES})
        configure_file(${f} ${f} COPYONLY)
    endforeach()
endfunction()

macro(SUBDIRLIST result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${curdir}/${child} AND EXISTS ${curdir}/${child}/CMakeLists.txt)
            list(APPEND dirlist ${child})
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()
