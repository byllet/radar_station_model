#include "FlyingObjectParameters.h"
#include "ui_object_parameters.h"

object_parameters::object_parameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::object_parameters)
{
    ui->setupUi(this);
}

object_parameters::~object_parameters()
{
    delete ui;
}

void object_parameters::on_create_new_obj_clicked()
{
    double object_coord_x = ui->obj_coord_x->text().toDouble();
    double object_coord_y = ui->obj_coord_y->text().toDouble();
    double object_coord_z = ui->obj_coord_z->text().toDouble();
    double object_speed_x = ui->obj_speed_x->text().toDouble();
    double object_speed_y = ui->obj_speed_y->text().toDouble();
    double object_speed_z = ui->obj_speed_z->text().toDouble();
    double object_accel_x = ui->obj_accel_x->text().toDouble();
    double object_accel_y = ui->obj_accel_y->text().toDouble();
    double object_accel_z = ui->obj_accel_z->text().toDouble();

    Plane* new_obj = new Plane({object_coord_x, object_coord_y, object_coord_z}, {object_speed_x, object_speed_y, object_speed_z}, {object_accel_x, object_accel_y, object_accel_z});
    emit obj_parameters_changed(new_obj);
    this->close();
}

