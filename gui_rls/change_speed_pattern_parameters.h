#ifndef CHANGE_SPEED_PATTERN_PARAMETERS_H
#define CHANGE_SPEED_PATTERN_PARAMETERS_H

#include <QDialog>

namespace Ui {
class change_speed_pattern_parameters;
}

class change_speed_pattern_parameters : public QDialog
{
    Q_OBJECT

public:
    explicit change_speed_pattern_parameters(QWidget *parent = nullptr);
    ~change_speed_pattern_parameters();

signals:
    void add_new_pattern(double desired_speed);

private slots:
    void on_add_new_pattern_clicked();

private:
    Ui::change_speed_pattern_parameters *ui;
};

#endif // CHANGE_SPEED_PATTERN_PARAMETERS_H
