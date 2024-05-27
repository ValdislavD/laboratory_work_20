cmake_minimum_required(VERSION 3.26)
project(untitled28 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled28 task_1-2_4-7_test.c
        thread_io/thread_io.h
        thread_io/thread_io.c
        thread_io/test_thread_io.c
        task_3.c
        task_4.c
        thread_io/vector.h
        thread_io/vector.c
        task_9_/task_9.c
        file_test_9.txt

)
