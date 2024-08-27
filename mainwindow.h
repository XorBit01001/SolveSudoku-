#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "sudoku_solver.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void solveSudoku();

private:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit* cells[9][9];
    SudokuSolver solver;
};

#endif // MAINWINDOW_H
