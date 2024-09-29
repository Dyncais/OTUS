cmake_minimum_required(VERSION 3.10)
project(MyProject)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(MyProject main.cpp)
target_link_libraries(MyProject gtest_main)
add_test(NAME example_test COMMAND example)