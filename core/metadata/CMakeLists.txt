cmake_minimum_required (VERSION 3.0)

project (lydia_metadata C)

INCLUDE_DIRECTORIES(../)
INCLUDE_DIRECTORIES(../../common)

SET(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/metadata.c
    )

add_executable(${PROJECT_NAME} ${SOURCES})