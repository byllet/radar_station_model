#include "SpeedParameterWindow.h"
#include "ui_change_speed_pattern_parameters.h"

change_speed_pattern_parameters::change_speed_pattern_parameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_speed_pattern_parameters)
{
    ui->setupUi(this);
}

change_speed_pattern_parameters::~change_speed_pattern_parameters()
{
    delete ui;
}

void change_speed_pattern_parameters::on_add_new_pattern_clicked()
{
    double desired_speed = ui->desired_speed->text().toDouble();
    emit add_new_pattern(desired_speed);
    this->close();
}

