#ifndef FLYINGOBJECTPARAMETERS_H
#define FLYINGOBJECTPARAMETERS_H

#include <QDialog>
#include "../src/air_models/Plane.hpp"


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
    void on_create_new_obj_clicked();

signals:
    void obj_parameters_changed(Plane*, size_t index = -1);

private:
    Ui::object_parameters *ui;
};

#endif // FLYINGOBJECTPARAMETERS_H
