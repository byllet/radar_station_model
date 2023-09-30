/********************************************************************************
** Form generated from reading UI file 'object_parameters.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECT_PARAMETERS_H
#define UI_OBJECT_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_object_parameters
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QSplitter *splitter_4;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *lineEdit;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *lineEdit_9;
    QGroupBox *groupBox_2;
    QSplitter *splitter_5;
    QSplitter *splitter_6;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QSplitter *splitter_7;
    QLabel *label_8;
    QLineEdit *lineEdit_10;
    QSplitter *splitter_8;
    QLabel *label_9;
    QLineEdit *lineEdit_11;
    QSplitter *splitter_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *object_parameters)
    {
        if (object_parameters->objectName().isEmpty())
            object_parameters->setObjectName("object_parameters");
        object_parameters->resize(424, 421);
        widget = new QWidget(object_parameters);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 381, 331));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(16777215, 140));
        groupBox->setFlat(false);
        splitter_4 = new QSplitter(groupBox);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setGeometry(QRect(20, 40, 341, 77));
        splitter_4->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName("label");
        splitter->addWidget(label);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(150, 16777215));
        splitter->addWidget(lineEdit);
        splitter_4->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName("label_2");
        splitter_2->addWidget(label_2);
        lineEdit_4 = new QLineEdit(splitter_2);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);
        lineEdit_4->setMaximumSize(QSize(150, 16777215));
        splitter_2->addWidget(lineEdit_4);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName("label_3");
        splitter_3->addWidget(label_3);
        lineEdit_9 = new QLineEdit(splitter_3);
        lineEdit_9->setObjectName("lineEdit_9");
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);
        lineEdit_9->setMaximumSize(QSize(150, 16777215));
        splitter_3->addWidget(lineEdit_9);
        splitter_4->addWidget(splitter_3);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMaximumSize(QSize(16777215, 140));
        groupBox_2->setFlat(false);
        splitter_5 = new QSplitter(groupBox_2);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setGeometry(QRect(20, 40, 341, 77));
        splitter_5->setOrientation(Qt::Vertical);
        splitter_6 = new QSplitter(splitter_5);
        splitter_6->setObjectName("splitter_6");
        splitter_6->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(splitter_6);
        label_7->setObjectName("label_7");
        splitter_6->addWidget(label_7);
        lineEdit_2 = new QLineEdit(splitter_6);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMaximumSize(QSize(150, 16777215));
        splitter_6->addWidget(lineEdit_2);
        splitter_5->addWidget(splitter_6);
        splitter_7 = new QSplitter(splitter_5);
        splitter_7->setObjectName("splitter_7");
        splitter_7->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(splitter_7);
        label_8->setObjectName("label_8");
        splitter_7->addWidget(label_8);
        lineEdit_10 = new QLineEdit(splitter_7);
        lineEdit_10->setObjectName("lineEdit_10");
        sizePolicy.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy);
        lineEdit_10->setMaximumSize(QSize(150, 16777215));
        splitter_7->addWidget(lineEdit_10);
        splitter_5->addWidget(splitter_7);
        splitter_8 = new QSplitter(splitter_5);
        splitter_8->setObjectName("splitter_8");
        splitter_8->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(splitter_8);
        label_9->setObjectName("label_9");
        splitter_8->addWidget(label_9);
        lineEdit_11 = new QLineEdit(splitter_8);
        lineEdit_11->setObjectName("lineEdit_11");
        sizePolicy.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy);
        lineEdit_11->setMaximumSize(QSize(150, 16777215));
        splitter_8->addWidget(lineEdit_11);
        splitter_5->addWidget(splitter_8);

        verticalLayout->addWidget(groupBox_2);

        splitter_9 = new QSplitter(object_parameters);
        splitter_9->setObjectName("splitter_9");
        splitter_9->setGeometry(QRect(200, 370, 200, 32));
        splitter_9->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter_9);
        pushButton->setObjectName("pushButton");
        splitter_9->addWidget(pushButton);
        pushButton_2 = new QPushButton(splitter_9);
        pushButton_2->setObjectName("pushButton_2");
        splitter_9->addWidget(pushButton_2);

        retranslateUi(object_parameters);
        QObject::connect(pushButton, &QPushButton::clicked, object_parameters, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(object_parameters);
    } // setupUi

    void retranslateUi(QDialog *object_parameters)
    {
        object_parameters->setWindowTitle(QCoreApplication::translate("object_parameters", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("object_parameters", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213", nullptr));
        label->setText(QCoreApplication::translate("object_parameters", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260 \320\277\320\276 \320\276\321\201\320\270 X", nullptr));
        label_2->setText(QCoreApplication::translate("object_parameters", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260 \320\277\320\276 \320\276\321\201\320\270 Y", nullptr));
        label_3->setText(QCoreApplication::translate("object_parameters", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260 \320\277\320\276 \320\276\321\201\320\270 Z", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("object_parameters", "\320\232\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202\321\213 \320\262\320\265\320\272\321\202\320\276\321\200\320\260 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("object_parameters", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 X", nullptr));
        label_8->setText(QCoreApplication::translate("object_parameters", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 Y", nullptr));
        label_9->setText(QCoreApplication::translate("object_parameters", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 Z", nullptr));
        pushButton->setText(QCoreApplication::translate("object_parameters", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("object_parameters", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class object_parameters: public Ui_object_parameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECT_PARAMETERS_H
