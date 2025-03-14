cmake_minimum_required(VERSION 3.20)
project(Hello2025)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "Codeforces - Hello 2025/*.cpp")
add_executable(B_Gorilla_and_the_Exam "Codeforces - Hello 2025/B_Gorilla_and_the_Exam.cpp")
add_executable(C_Trip_to_the_Olympiad "Codeforces - Hello 2025/C_Trip_to_the_Olympiad.cpp")
add_executable(E1_Another_Exercise_on_Graphs_Easy_Version "Codeforces - Hello 2025/E1_Another_Exercise_on_Graphs_Easy_Version.cpp")
add_executable(D_Gifts_Order "Codeforces - Hello 2025/D_Gifts_Order.cpp")