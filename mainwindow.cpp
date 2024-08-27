#include "mainwindow.h"
#include <QWidget>
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col] = new QLineEdit;
            cells[row][col]->setMaxLength(1);
            cells[row][col]->setAlignment(Qt::AlignCenter);
            cells[row][col]->setFixedSize(48, 48);

            QIntValidator *validator = new QIntValidator(1, 9, this);
            cells[row][col]->setValidator(validator);

            QString style = "font-size: 40px; border: 1px solid black;";

            if (row % 3 == 0 && row != 0)
                style += "border-top: 3px solid black;";
            if (col % 3 == 0 && col != 0)
                style += "border-left: 3px solid black;";
            if (row == 8)
                style += "border-bottom: 3px solid black;";
            if (col == 8)
                style += "border-right: 3px solid black;";

            cells[row][col]->setStyleSheet(style);
            gridLayout->addWidget(cells[row][col], row, col);
        }
    }


    QPushButton *solveButton = new QPushButton("Solve", this);
    gridLayout->addWidget(solveButton, 9, 0, 1, 9);
    connect(solveButton, &QPushButton::clicked, this, &MainWindow::solveSudoku);
}

void MainWindow::solveSudoku() {
    std::vector<std::vector<int>> board(9, std::vector<int>(9, 0));

    // Read data from UI into board
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            bool ok;
            int value = cells[row][col]->text().toInt(&ok);
            if (ok) {
                board[row][col] = value;
            }
        }
    }

    // Solve the Sudoku
    if (solver.solve(board)) {
        // Update UI with the solution
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                cells[row][col]->setText(QString::number(board[row][col]));
            }
        }
    } else {
        QMessageBox::information(this, "Error", "The puzzle cannot be solved.");
    }
}
