#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <vector>

class SudokuSolver {
public:
    SudokuSolver();
    bool solve(std::vector<std::vector<int>>& board);
    void printBoard(const std::vector<std::vector<int>>& board) const;

private:
    bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num);
};

#endif // SUDOKU_SOLVER_H
