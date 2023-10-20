#include "object_parameters.h"
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

void object_parameters::on_pushButton_2_clicked()
{
    double object_coord_x = ui->obj_coord_x->text().toDouble();
    double object_coord_y = ui->obj_coord_y->text().toDouble();
//    double object_coord_z = ui->obj_coord_z->text().toDouble();
    double object_speed_x = ui->obj_speed_x->text().toDouble();
    double object_speed_y = ui->obj_speed_y->text().toDouble();
//    double object_speed_z = ui->obj_speed_z->text().toDouble();
    Object new_obj(object_coord_x, object_coord_y, 0, object_speed_x, object_speed_y, 0);
    emit obj_parameters_changed(new_obj);
    this->close();
}

