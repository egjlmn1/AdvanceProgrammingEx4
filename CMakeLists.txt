cmake_minimum_required(VERSION 3.15)
project(FlightSimulatorMaster)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(AdvanceProgrammingEx4
        main.cpp

        Interfaces.h

        MySerialServer.cpp MySerialServer.h
        MyTestClientHandler.cpp MyTestClientHandler.h
        FileCacheManager.cpp FileCacheManager.h

        Problems/StringProblem.cpp Problems/StringProblem.h
        Solutions/StringSolution.cpp Solutions/StringSolution.h
        Solvers/StringReverser.cpp Solvers/StringReverser.h
        Solutions/Solution.cpp Solutions/Solution.h
        MyParallelServer.cpp MyParallelServer.h

        SearchingAlgorithms/State.h
        SearchingAlgorithms/MyPriorityQueue.h
        SearchingAlgorithms/StateComparator.h

        SearchingAlgorithms/Searchable/ISearchable.h
        SearchingAlgorithms/Searchable/MatrixSearchable.h
        SearchingAlgorithms/Searchable/MatrixSearchable.cpp

        SearchingAlgorithms/Searchers/ISearcher.h
        SearchingAlgorithms/Searchers/Searcher.h
        SearchingAlgorithms/Searchers/BestFirstSearch.h
        SearchingAlgorithms/Searchers/BreadthFirstSearch.h
        SearchingAlgorithms/Searchers/DepthFirstSearch.h
        SearchingAlgorithms/Searchers/AStar.h

        SearchableSolutionAdapter/MatrixSearchSolverAdapter.cpp SearchableSolutionAdapter/MatrixSearchSolverAdapter.h
        Problems/MatrixProblem.cpp Problems/MatrixProblem.h SearchingAlgorithms/AddHeuristicComparator.h)
