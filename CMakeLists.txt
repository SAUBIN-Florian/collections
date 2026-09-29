cmake_minimum_required(VERSION 3.20)

# DEBUG purpose only, will be deleted later
project(Array_example)
add_executable(Array_example 
	examples/array_ex.c
	include/array.h src/array.c
)
