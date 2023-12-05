#include "rls.h"
#include "ui_rls.h"

RLS::RLS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RLS)
{
    ui->setupUi(this);
}

RLS::~RLS()
{
    delete ui;
}

void RLS::on_add_signals_timer_clicked()
{
    double signals_timer = ui->signals_timer->text().toDouble();
    emit add_signals_timer(signals_timer);
    this->close();
}
