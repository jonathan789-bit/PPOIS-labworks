cmake_minimum_required(VERSION 3.14)
project(PostMachineProject)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# --- Google Test Setup ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# --------------------------

add_library(
    PostMachineLibrary
    src/PostMachine.cpp
)

target_include_directories(
    PostMachineLibrary
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(
    PostMachineApp
    src/main.cpp
)

target_link_libraries(
    PostMachineApp
    PostMachineLibrary
)

# --- Test Configuration ---
enable_testing()

add_executable(
    PostMachineTests
    test/PostMachineTests.cpp
)

target_link_libraries(
    PostMachineTests
    PostMachineLibrary
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(PostMachineTests)