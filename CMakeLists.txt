cmake_minimum_required(VERSION 3.13)  # CMake version check
project(UartServer)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Your-external "mylib", add GLOBAL if the imported library is located in directories above the current.
#add_library( modbus SHARED IMPORTED )
# You can define two import-locations: one for debug and one for release.
#set_target_properties( modbus PROPERTIES IMPORTED_LOCATION /usr/local/lib/libmodbus.so)

include_directories(./inc)

# Add main.cpp file of project root directory as source file
#set(SOURCE_FILES Uart_test.cpp)
#set(SOURCE_FILES Latency_test.cpp)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(UartServer Uart_test.cpp)
add_executable(Throughput_test  Troughput_test.cpp)
add_executable(Latency_test  Latency_test.cpp)
add_executable(IO_test  IO_Test.cpp)
add_executable(Measure_temp  Measure_temp.cpp)

