cmake_minimum_required(VERSION 4.0)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSA
        ALL.cpp
        Array.h
        Graph.h
        Infix2Postfix.h
        LinkedList.h
        Node.h
        Pointer.h
        Queue.h
        Search.h
        Sort.h
        Stack.h
        String.h
        Tree.h)
