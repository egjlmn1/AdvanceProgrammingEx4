# Problem Solver

The Problem Solver is used for solving problems.

This Problem Solver:

Has a server

Is able to accept up to 10 clients

Can run search algorithms such as BestFirstSearch, DFS, BFS and A*.


## Link to GitHub

https://github.com/egjlmn1/AdvanceProgrammingEx4


## Installation

Now, download ex4.zip

Unzip ex4.zip:

```bash
unzip ex4.zip
```

## Usage

If you want to use another algorithm change it in the MatrixSolver class in the solve function. Change the Searcher from AStar to anything you want.

Now we can run the program.‬‬

Compile the program using the g++ compiler with the line

```bash
g++ -std=c++14 *.cpp */*.cpp */*/*.cpp */*/*/*.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
```

Then, execute that program while passing the port you want to bind as an argument:
```bash
./a.out port
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
