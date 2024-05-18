/********************************************************************************
** Form generated from reading UI file 'superviseClientWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERVISECLIENTWIDGET_H
#define UI_SUPERVISECLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_superviseClientWidget
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelMjpg;
    QGridLayout *gridLayout;
    QLabel *labelJpeg1;
    QLabel *labelJpeg2;
    QLabel *labelJpeg3;
    QLabel *labelJpeg4;
    QPushButton *btnGetMjpg;
    QPushButton *btnGetJpeg;

    void setupUi(QWidget *superviseClientWidget)
    {
        if (superviseClientWidget->objectName().isEmpty())
            superviseClientWidget->setObjectName("superviseClientWidget");
        superviseClientWidget->resize(689, 334);
        gridLayout_2 = new QGridLayout(superviseClientWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        labelMjpg = new QLabel(superviseClientWidget);
        labelMjpg->setObjectName("labelMjpg");
        labelMjpg->setFrameShape(QFrame::Box);
        labelMjpg->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(labelMjpg, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelJpeg1 = new QLabel(superviseClientWidget);
        labelJpeg1->setObjectName("labelJpeg1");
        labelJpeg1->setFrameShape(QFrame::Box);
        labelJpeg1->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg1, 0, 0, 1, 1);

        labelJpeg2 = new QLabel(superviseClientWidget);
        labelJpeg2->setObjectName("labelJpeg2");
        labelJpeg2->setFrameShape(QFrame::Box);
        labelJpeg2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg2, 0, 1, 1, 1);

        labelJpeg3 = new QLabel(superviseClientWidget);
        labelJpeg3->setObjectName("labelJpeg3");
        labelJpeg3->setFrameShape(QFrame::Box);
        labelJpeg3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg3, 1, 0, 1, 1);

        labelJpeg4 = new QLabel(superviseClientWidget);
        labelJpeg4->setObjectName("labelJpeg4");
        labelJpeg4->setFrameShape(QFrame::Box);
        labelJpeg4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg4, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        btnGetMjpg = new QPushButton(superviseClientWidget);
        btnGetMjpg->setObjectName("btnGetMjpg");

        gridLayout_2->addWidget(btnGetMjpg, 1, 0, 1, 1);

        btnGetJpeg = new QPushButton(superviseClientWidget);
        btnGetJpeg->setObjectName("btnGetJpeg");

        gridLayout_2->addWidget(btnGetJpeg, 1, 1, 1, 1);


        retranslateUi(superviseClientWidget);

        QMetaObject::connectSlotsByName(superviseClientWidget);
    } // setupUi

    void retranslateUi(QWidget *superviseClientWidget)
    {
        superviseClientWidget->setWindowTitle(QCoreApplication::translate("superviseClientWidget", "\350\277\234\347\250\213\350\247\206\351\242\221\347\233\221\346\216\247\347\263\273\347\273\237", nullptr));
        labelMjpg->setText(QString());
        labelJpeg1->setText(QString());
        labelJpeg2->setText(QString());
        labelJpeg3->setText(QString());
        labelJpeg4->setText(QString());
        btnGetMjpg->setText(QCoreApplication::translate("superviseClientWidget", "\350\216\267\345\217\226\350\247\206\351\242\221", nullptr));
        btnGetJpeg->setText(QCoreApplication::translate("superviseClientWidget", "\350\216\267\345\217\226\345\277\253\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class superviseClientWidget: public Ui_superviseClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERVISECLIENTWIDGET_H
