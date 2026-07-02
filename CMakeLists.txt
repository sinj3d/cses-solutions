cmake_minimum_required(VERSION 3.15)
project(cses-solutions CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default to Debug if nothing specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Flags per build type
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wshadow -DLOCAL")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -Wall -Wextra")

# ASan/UBSan are available on Linux/Clang but MinGW-w64 ships no libasan/libubsan,
# so only enable them where the runtime libraries actually exist.
if(NOT WIN32)
  string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-fsanitize=address,undefined")
endif()

# Recursively find every .cpp file in subfolders
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(SRC ${SOURCES})
    # Turn "sorting-and-searching/sol.cpp" into target name "sol"
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)

    # Guard against duplicate filenames across folders
    if(TARGET ${TARGET_NAME})
        get_filename_component(DIR_NAME ${SRC} DIRECTORY)
        get_filename_component(DIR_NAME ${DIR_NAME} NAME)
        set(TARGET_NAME "${DIR_NAME}_${TARGET_NAME}")
    endif()

    add_executable(${TARGET_NAME} ${SRC})

    # Put each binary next to its source file, not all dumped in build/
    get_filename_component(SRC_DIR ${SRC} DIRECTORY)
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${SRC_DIR}"
    )
endforeach()