#include "sudoku_solver.h"
#include <iostream>

SudokuSolver::SudokuSolver() {}

bool SudokuSolver::solve(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve(board)) {
                            return true;
                        }
                        board[row][col] = 0; // Undo move
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved
}

bool SudokuSolver::isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    // Check row
    for (int x = 0; x < 9; ++x) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < 9; ++x) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

void SudokuSolver::printBoard(const std::vector<std::vector<int>>& board) const {
    for (const auto& row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
