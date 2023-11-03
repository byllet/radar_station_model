#include "rev_pattern_parameters.h"
#include "ui_rev_pattern_parameters.h"

rev_pattern_parameters::rev_pattern_parameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rev_pattern_parameters)
{
    ui->setupUi(this);
}

rev_pattern_parameters::~rev_pattern_parameters()
{
    delete ui;
}

void rev_pattern_parameters::on_add_new_pattern_clicked()
{
    double radius = ui->radius->text().toDouble();
    emit add_new_pattern(radius);
    this->close();
}
