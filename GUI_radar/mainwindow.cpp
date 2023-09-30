#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <object_parameters.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    object_parameters object_window;
    object_window.setModal(true);
    object_window.exec();
}

