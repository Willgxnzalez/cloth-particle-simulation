cmake_minimum_required(VERSION 3.10)
project(ClothSimulation)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# output directory
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# =============================================================================
# Fetch SFML via FetchContent
# =============================================================================
include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.0
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/core)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# =============================================================================
# Executable target
# =============================================================================
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)



# =============================================================================
# On Windows, copy DLLs next to the .exe if building shared SFML
# =============================================================================
if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
      COMMENT "Copying SFML DLLs to output directory"
    )
endif()