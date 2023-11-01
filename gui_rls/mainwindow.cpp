#include "mainwindow.h"
#include "object_parameters.h"
#include "ui_mainwindow.h"
#include "ui_object_parameters.h"
#include "glwidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);
    glwidget = new GLWidget(this);
    ui->verticalLayout_5->addWidget(glwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete new_object_window;
    delete glwidget;
}

void MainWindow::on_add_object_clicked()
{
    new_object_window = new object_parameters(this);
    new_object_window->show();
    connect(new_object_window, &object_parameters::obj_parameters_changed, glwidget, &GLWidget::addNewObj);
    connect(new_object_window, &object_parameters::obj_parameters_changed, this, &MainWindow::add_obj_to_combobox);
}

void MainWindow::add_obj_to_combobox()
{
    QString item_text = "Aircraft №" + QString::number(ui->comboBox->count());
    ui->comboBox->addItem(item_text);
}

void MainWindow::on_delete_object_clicked()
{
    size_t current_index = ui->comboBox->currentIndex();
    ui->comboBox->removeItem(current_index);
    glwidget->manager.GetFlyingObjects().erase(glwidget->manager.GetFlyingObjects().begin() + current_index);
    glwidget->update();
}


void MainWindow::on_start_modeling_clicked()
{
    glwidget->tmr.start(33);
}


void MainWindow::on_stop_modeling_clicked()
{
    glwidget->tmr.stop();
}

