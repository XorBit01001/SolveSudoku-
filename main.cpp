#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Sudoku Solver");
    window.resize(400, 400); // Adjust size as needed
    window.show();

    return app.exec();
}
