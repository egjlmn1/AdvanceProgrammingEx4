cmake_minimum_required(VERSION 3.15)
project(FlightSimulatorMaster)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Project
        main.cpp

        Inteface.h
        MySerialServer.cpp MySerialServer.h
        MyTestClientHandler.cpp MyTestClientHandler.h
        FileCacheManager.cpp FileCacheManager.h

        Problems/StringProblem.cpp Problems/StringProblem.h
        Solutions/StringSolution.cpp Solutions/StringSolution.h Solutions/Solution.h Solutions/Solution.cpp
        Solvers/StringReverser.cpp Solvers/StringReverser.h

        SearchingAlgorithms/State.cpp
        SearchingAlgorithms/State.h
        SearchingAlgorithms/Searchable/ISearchable.h
        SearchingAlgorithms/Searchable/MatrixSearchable.h
        SearchingAlgorithms/Searchable/MatrixSearchable.cpp
        SearchingAlgorithms/Searchers/ISearcher.h
        SearchingAlgorithms/Searchers/Searcher.h
        SearchingAlgorithms/Searchers/Searcher.cpp
        SearchingAlgorithms/Searchers/BestFirstSearch.h
        SearchingAlgorithms/Searchers/BestFirstSearch.cpp
        SearchingAlgorithms/MyPriorityQueue.h
        SearchingAlgorithms/MyPriorityQueue.cpp
        SearchingAlgorithms/StateComparator.h


        )
