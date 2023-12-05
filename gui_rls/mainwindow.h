#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include "FlyingObject/FlyingObjectParameters.h"
#include "OpenGLWidget.h"
#include "Patterns/ReverseParameterWindow.h"
#include "Patterns/HeightParameterWindow.h"
#include "Patterns/SpeedParameterWindow.h"
#include "rls.h"
#include "../src/Manager.hpp"
#include "../src/patterns/ReversalPattern.hpp"
#include "../src/patterns/ChangeHeightPattern.hpp"
#include "../src/patterns/ChangeSpeedPattern.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_object_clicked();
    void add_obj_to_combobox();
    void on_delete_object_clicked();
    void on_start_modeling_clicked();
    void on_stop_modeling_clicked();
    void on_reversal_button_clicked();
    void add_new_reversal_pattern(double);
    void on_change_speed_button_clicked();
    void add_new_change_speed_pattern(double);
    void on_change_height_button_clicked();
    void add_new_change_height_pattern(double);
    void on_RLS_param_clicked();
    void add_new_signals_timer(double);


    void on_add_signals_clicked();

private:
    Ui::GUI *ui;
    RLS *rls_param;
    object_parameters *new_object_window;
    rev_pattern_parameters *new_reversal_pattern_window;
    change_height_pattern_parameters *new_change_height_pattern_window;
    change_speed_pattern_parameters *new_change_speed_pattern_window;
    GLWidget *glwidget;

};
#endif // MAINWINDOW_H
