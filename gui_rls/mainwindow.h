#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include "object_parameters.h"
#include "glwidget.h"

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
    void add_obj_to_combobox(Object new_obj, size_t index = -1);
    void on_delete_object_clicked();
    void on_start_modeling_clicked();
    void on_stop_modeling_clicked();

private:
    Ui::GUI *ui;
    object_parameters *new_object_window;
    GLWidget *glwidget;

};
#endif // MAINWINDOW_H
