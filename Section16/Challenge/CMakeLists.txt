cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(main)
add_executable(main src/main.cpp src/Account_Util.cpp src/Account.cpp
               src/Checking_Account.cpp src/Savings_Account.cpp
               src/Trust_Account.cpp)