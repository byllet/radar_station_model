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

}

