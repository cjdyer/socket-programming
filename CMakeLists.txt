cmake_minimum_required(VERSION 3.10)
project(SocketProgramming)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Server src/server.cpp src/server_main.cpp src/message.cpp)
add_executable(Client src/client.cpp src/client_main.cpp src/message.cpp)

# Testing
enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}Test unittests/test_client.cpp)

target_link_libraries(${PROJECT_NAME}Test GTest::GTest GTest::Main)

# Add the tests
add_test(
  NAME ${PROJECT_NAME}Test
  COMMAND ${PROJECT_NAME}Test
)
