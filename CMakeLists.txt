cmake_minimum_required(VERSION 3.16)          

project("market-making-sim" VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 11.0.2  
)

FetchContent_MakeAvailable(fmt)

add_executable(main "src/main.cpp" "src/Test.cpp") 
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include) 

target_link_libraries(main PRIVATE fmt::fmt)