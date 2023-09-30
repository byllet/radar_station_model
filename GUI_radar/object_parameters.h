#ifndef OBJECT_PARAMETERS_H
#define OBJECT_PARAMETERS_H

#include <QDialog>

namespace Ui {
class object_parameters;
}

class object_parameters : public QDialog
{
    Q_OBJECT

public:
    explicit object_parameters(QWidget *parent = nullptr);
    ~object_parameters();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::object_parameters *ui;
};

#endif // OBJECT_PARAMETERS_H
