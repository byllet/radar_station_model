#include "mainwindow.h"
#include "FlyingObject/FlyingObjectParameters.h"
#include "ui_mainwindow.h"
#include "ui_FlyingObjectParameters.h"
#include "OpenGLWidget/OpenGLWidget.h"


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
    delete new_change_height_pattern_window;
    delete new_change_speed_pattern_window;
    delete new_reversal_pattern_window;
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
    delete glwidget->manager.GetFlyingObjects()[current_index];
    glwidget->manager.GetFlyingObjects().erase(glwidget->manager.GetFlyingObjects().begin() + current_index);
    glwidget->update();
}


void MainWindow::on_start_modeling_clicked()
{
    glwidget->tmr.start(66);
    glwidget->log_tmr.start(750);
}


void MainWindow::on_stop_modeling_clicked()
{
    glwidget->tmr.stop();
    glwidget->log_tmr.stop();
}


void MainWindow::on_reversal_button_clicked()
{
    new_reversal_pattern_window = new rev_pattern_parameters(this);
    new_reversal_pattern_window->show();
    connect(new_reversal_pattern_window, &rev_pattern_parameters::add_new_pattern, this, &MainWindow::add_new_reversal_pattern);
}

void MainWindow::add_new_reversal_pattern(double radius)
{
    size_t current_index = ui->comboBox->currentIndex();
    glwidget->manager.AddNewPattern(glwidget->manager.GetFlyingObjects()[current_index], new ReversalPattern(radius));
}

void MainWindow::on_change_height_button_clicked()
{
    new_change_height_pattern_window = new change_height_pattern_parameters(this);
    new_change_height_pattern_window->show();
    connect(new_change_height_pattern_window, &change_height_pattern_parameters::add_new_pattern, this, &MainWindow::add_new_change_height_pattern);
}

void MainWindow::add_new_change_height_pattern(double h)
{
    size_t current_index = ui->comboBox->currentIndex();
    glwidget->manager.AddNewPattern(glwidget->manager.GetFlyingObjects()[current_index], new ChangeHeightPattern(h));
}

void MainWindow::on_change_speed_button_clicked()
{
    new_change_speed_pattern_window = new change_speed_pattern_parameters(this);
    new_change_speed_pattern_window->show();
    connect(new_change_speed_pattern_window, &change_speed_pattern_parameters::add_new_pattern, this, &MainWindow::add_new_change_speed_pattern);
}

void MainWindow::add_new_change_speed_pattern(double desired_speed)
{
    size_t current_index = ui->comboBox->currentIndex();
    glwidget->manager.AddNewPattern(glwidget->manager.GetFlyingObjects()[current_index], new ChangeSpeedPattern(desired_speed));
}

void MainWindow::on_RLS_param_clicked()
{
    rls_param = new RLS(this);
    rls_param->show();
    connect(rls_param, &RLS::add_signals_timer, this, &MainWindow::add_new_signals_timer);
}

void MainWindow::add_new_signals_timer(double t)
{
    glwidget->manager.SetTimeForRadar(t);
}


void MainWindow::on_add_signals_clicked()
{
    std::vector<Signal> signals_v = glwidget->manager.GetRadar().Start(200);
    glwidget->manager.TakeNewSignals(signals_v);
}

