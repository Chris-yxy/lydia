cmake_minimum_required (VERSION 3.0)

project (lydia_core C)

INCLUDE_DIRECTORIES(../)
INCLUDE_DIRECTORIES(../common)
INCLUDE_DIRECTORIES(../tlv)

SET(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/lydia_core.c
    )

add_executable(${PROJECT_NAME} ${SOURCES})