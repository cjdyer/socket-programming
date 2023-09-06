cmake_minimum_required(VERSION 3.10)
project(SocketProgramming)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Server src/server.cpp src/server_main.cpp src/message.cpp)
add_executable(Client src/client.cpp src/client_main.cpp src/message.cpp)

# Testing
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}Test unittests/test_message.cpp src/message.cpp)

target_link_libraries(${PROJECT_NAME}Test gtest gtest_main pthread)

# Add the tests
add_test(
  NAME ${PROJECT_NAME}Test
  COMMAND ${PROJECT_NAME}Test
)
