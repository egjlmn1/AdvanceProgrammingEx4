cmake_minimum_required(VERSION 3.15)
project(FlightSimulatorMaster)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Project
        main.cpp

        Inteface.h

        SearchingAlgorithms/State.h
        SearchingAlgorithms/Searchable/ISearchable.h
        SearchingAlgorithms/Searchable/MatrixSearchable.h
        SearchingAlgorithms/Searchable/MatrixSearchable.cpp
        SearchingAlgorithms/Searchers/ISearcher.h
        SearchingAlgorithms/Searchers/Searcher.h
        SearchingAlgorithms/Searchers/BestFirstSearch.h
        SearchingAlgorithms/MyPriorityQueue.h
        SearchingAlgorithms/StateComparator.h SearchingAlgorithms/StateComparator.cpp)
