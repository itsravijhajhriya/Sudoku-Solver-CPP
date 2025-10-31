# Sudoku-Solver-CPP
A simple C++ program that solves any valid Sudoku.
C++ Sudoku Solver
This is a high-performance Sudoku puzzle solver built in C++ using a backtracking algorithm. This project demonstrates the implementation of a core recursive algorithm for solving complex constraint-satisfaction problems.

Core Logic & Features
Algorithm: Implements a recursive backtracking algorithm to efficiently explore the solution space.

Validation: The isGood() function validates each number against row, column, and 3x3 sub-grid constraints.

Efficiency: The solver() function iterates through empty cells (marked as 0), tries potential numbers from 1-9, and backtracks immediately if a path leads to an invalid state, ensuring an optimized search.

Data Structure: Uses a vector<vector<int>> (2D Vector) to represent the 9x9 Sudoku grid, allowing for dynamic and easy-to-manage grid manipulation.
