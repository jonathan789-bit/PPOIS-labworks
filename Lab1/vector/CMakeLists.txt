cmake_minimum_required(VERSION 3.14)
project(VectorProject)

# --- Google Test Setup ---
# GoogleTest requires at least C++14 (or 17 for newer versions)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# --------------------------

# Your existing library
add_library(
    VectorLibrary
    src/Vector.cpp
)

target_include_directories(
    VectorLibrary
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Your existing app
add_executable(
    VectorApp
    src/main.cpp
)
target_link_libraries(VectorApp VectorLibrary)

# --- Test Configuration ---
enable_testing()

add_executable(
    VectorTests
    test/VectorTests.cpp
)

# Link your library and Google Test to your tests
target_link_libraries(
    VectorTests
    VectorLibrary
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(VectorTests)