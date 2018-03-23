cmake_minimum_required(VERSION 3.9)
project(Map C)

set(CMAKE_C_STANDARD 90)

add_executable(Map main.c

                    debug_log.h


                    list/list.c
                    list/list.h

                    list/list_iterator.c
                    list/list_iterator.h

                    list/list_map.c
                    list/list_map.h
                )

add_definitions(-DDEBUG)