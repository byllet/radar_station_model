#ifndef RLS_H
#define RLS_H

#include <QDialog>

namespace Ui {
class RLS;
}

class RLS : public QDialog
{
    Q_OBJECT

public:
    explicit RLS(QWidget *parent = nullptr);
    ~RLS();

signals:
    void add_signals_timer(double desired_speed);

private slots:
    void on_add_signals_timer_clicked();

private:
    Ui::RLS *ui;
};

#endif // RLS_H
