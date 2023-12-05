#ifndef REVERSEPARAMETERWINDOW_H
#define REVERSEPARAMETERWINDOW_H

#include <QDialog>

namespace Ui {
class rev_pattern_parameters;
}

class rev_pattern_parameters : public QDialog
{
    Q_OBJECT

public:
    explicit rev_pattern_parameters(QWidget *parent = nullptr);
    ~rev_pattern_parameters();

signals:
    void add_new_pattern(double radius);

private slots:
    void on_add_new_pattern_clicked();

private:
    Ui::rev_pattern_parameters *ui;
};

#endif // REVERSEPARAMETERWINDOW_H
