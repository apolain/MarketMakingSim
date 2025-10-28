cmake_minimum_required(VERSION 3.21)          
project("market-making-sim" VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 11.0.2  
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.11.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(main "src/main.cpp") 

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include) 
target_link_libraries(main PRIVATE fmt::fmt)

add_executable(unit_tests "tests/book/test_order.cpp") 
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
