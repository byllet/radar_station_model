#include "change_height_pattern_parameters.h"
#include "ui_change_height_pattern_parameters.h"

change_height_pattern_parameters::change_height_pattern_parameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_height_pattern_parameters)
{
    ui->setupUi(this);
}

change_height_pattern_parameters::~change_height_pattern_parameters()
{
    delete ui;
}

void change_height_pattern_parameters::on_add_new_pattern_clicked()
{
    double height_difference = ui->height_difference->text().toDouble();
    emit add_new_pattern(height_difference);
    this->close();
}

