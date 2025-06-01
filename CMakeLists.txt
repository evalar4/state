cmake_minimum_required(VERSION 3.14)
project(StatePattern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройка выходных директорий
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Основная библиотека состояний
add_library(state STATIC
    src/Work.cpp
    src/ForenoonState.cpp
    src/NoonState.cpp
    src/AfternoonState.cpp
)

target_include_directories(state PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Основная программа
add_executable(state_program src/main.cpp)
target_link_libraries(state_program state)

# Тесты (только если найден GTest)
find_package(GTest REQUIRED)
if(GTest_FOUND)
    enable_testing()
    
    add_executable(state_tests
    	tests/test_main.cpp
        tests/test_forenoon.cpp
        tests/test_noon.cpp
        tests/test_afternoon.cpp
    )
    
    target_include_directories(state_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(state_tests
        state
        GTest::GTest
        GTest::Main
    )
    
    add_test(NAME state_tests COMMAND state_tests)
endif()

# Установка (опционально)
install(TARGETS state
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include/state)
