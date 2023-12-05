#ifndef HEIGHTPARAMETERWINDOW_H
#define HEIGHTPARAMETERWINDOW_H

#include <QDialog>

namespace Ui {
class change_height_pattern_parameters;
}

class change_height_pattern_parameters : public QDialog
{
    Q_OBJECT

public:
    explicit change_height_pattern_parameters(QWidget *parent = nullptr);
    ~change_height_pattern_parameters();

signals:
    void add_new_pattern(double height_difference);

private slots:
    void on_add_new_pattern_clicked();

private:
    Ui::change_height_pattern_parameters *ui;
};

#endif // HEIGHTPARAMETERWINDOW_H
