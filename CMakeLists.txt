cmake_minimum_required(VERSION 3.1)

project(example)

set(CMAKE_CXX_STANDARD 11)


set(EXAMPLE_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(EXAMPLE_PROJECT ON)
endif()


option(BUILD_EXAMPLES "Build examples. Uncheck for install only runs"
       ${EXAMPLE_PROJECT})

if (CMAKE_CXX_COMPILER_ID MATCHES "(Clang|GNU)")
	list(APPEND flags "-Wall" "-Wextra" "-Wshadow" "-Wnon-virtual-dtor" "-pedantic")
elseif(MSVC)
	list(APPEND flags "/W4" "/WX")
endif()
list(APPEND flags "-g")
list(APPEND flags "-O0")
add_executable(main main.cpp Animal.cpp NormalAnimals.cpp TestAnimals.cpp)
target_compile_options(main PRIVATE ${flags})
    
