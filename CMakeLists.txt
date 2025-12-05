# CMakeList.txt : CMake project for CompetitiveCoding, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CompetitiveCoding")

include_directories (${CMAKE_SOURCE_DIR})

# Add source to this project's executable.
add_executable (CompetitiveCoding "CompetitiveCoding.cpp" "CompetitiveCoding.h")

# Find all .cpp files (recursively)
file(GLOB_RECURSE PROBLEM_FILES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/leetcode/*.cpp
     ${CMAKE_SOURCE_DIR}/codeforces/*.cpp
)

file(GLOB_RECURSE LIB_FILES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/dsa/*.cpp
)

# Create one executable per problem
foreach(FILE ${PROBLEM_FILES})
    # Get path relative to project root
    file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${FILE})

    # Remove extension
    string(REPLACE ".cpp" "" TARGET_NAME ${REL_PATH})

    #Replace folder slashes with underscores
    string(REPLACE "/" "_" TARGET_NAME ${TARGET_NAME})
    string(REPLACE "\\" "_" TARGET_NAME ${TARGET_NAME})
    string(REPLACE " " "_" TARGET_NAME ${TARGET_NAME})

    add_executable(${TARGET_NAME} ${FILE} ${LIB_FILES})
endforeach()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CompetitiveCoding PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
