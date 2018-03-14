/********************************************************************************
** Form generated from reading UI file 'countline.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTLINE_H
#define UI_COUNTLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CountLineClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_file;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_add;
    QTableWidget *tableWidget_filePath;
    QLabel *label_progress;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_count;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_count;
    QTableWidget *tableWidget_countLine;

    void setupUi(QMainWindow *CountLineClass)
    {
        if (CountLineClass->objectName().isEmpty())
            CountLineClass->setObjectName(QStringLiteral("CountLineClass"));
        CountLineClass->resize(901, 567);
        centralWidget = new QWidget(CountLineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_file = new QLabel(centralWidget);
        label_file->setObjectName(QStringLiteral("label_file"));

        horizontalLayout->addWidget(label_file);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout->addWidget(pushButton_add);


        verticalLayout_3->addLayout(horizontalLayout);

        tableWidget_filePath = new QTableWidget(centralWidget);
        if (tableWidget_filePath->columnCount() < 2)
            tableWidget_filePath->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_filePath->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_filePath->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_filePath->setObjectName(QStringLiteral("tableWidget_filePath"));

        verticalLayout_3->addWidget(tableWidget_filePath);


        verticalLayout->addLayout(verticalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);

        label_progress = new QLabel(centralWidget);
        label_progress->setObjectName(QStringLiteral("label_progress"));
        label_progress->setMinimumSize(QSize(50, 0));
        label_progress->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(label_progress);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_count = new QLabel(centralWidget);
        label_count->setObjectName(QStringLiteral("label_count"));

        horizontalLayout_3->addWidget(label_count);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_count = new QPushButton(centralWidget);
        pushButton_count->setObjectName(QStringLiteral("pushButton_count"));

        horizontalLayout_3->addWidget(pushButton_count);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tableWidget_countLine = new QTableWidget(centralWidget);
        if (tableWidget_countLine->columnCount() < 2)
            tableWidget_countLine->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_countLine->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_countLine->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_countLine->setObjectName(QStringLiteral("tableWidget_countLine"));

        verticalLayout_2->addWidget(tableWidget_countLine);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_4);

        CountLineClass->setCentralWidget(centralWidget);

        retranslateUi(CountLineClass);

        QMetaObject::connectSlotsByName(CountLineClass);
    } // setupUi

    void retranslateUi(QMainWindow *CountLineClass)
    {
        CountLineClass->setWindowTitle(QApplication::translate("CountLineClass", "CountLine", 0));
        label_file->setText(QApplication::translate("CountLineClass", "\346\226\207\344\273\266\345\210\227\350\241\250", 0));
        pushButton_add->setText(QApplication::translate("CountLineClass", "\346\267\273\345\212\240", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_filePath->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CountLineClass", "\346\226\207\344\273\266\350\267\257\345\276\204", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_filePath->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CountLineClass", "\347\212\266\346\200\201", 0));
        label_progress->setText(QString());
        label_count->setText(QApplication::translate("CountLineClass", "\347\273\237\350\256\241\347\273\223\346\236\234", 0));
        pushButton_count->setText(QApplication::translate("CountLineClass", "\347\273\237\350\256\241", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_countLine->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("CountLineClass", "\345\220\216\347\274\200\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_countLine->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("CountLineClass", "\350\241\214\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class CountLineClass: public Ui_CountLineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTLINE_H
