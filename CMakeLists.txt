cmake_minimum_required(VERSION 3.25)
project(Employee_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Employee_System main.cpp workerManager.cpp workerManager.h worker.cpp worker.h worker.cpp worker.cpp employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
