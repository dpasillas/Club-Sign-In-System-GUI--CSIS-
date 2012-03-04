/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created: Sat Mar 3 22:46:22 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *host_line;
    QLabel *label_2;
    QLineEdit *user_line;
    QLabel *label_3;
    QLineEdit *password_line;
    QLabel *label_4;
    QLineEdit *database_line;
    QLabel *label_5;
    QLineEdit *port_line;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *semester_line;
    QLabel *label_8;
    QLineEdit *hours_per_person_line;
    QLabel *label_9;
    QCheckBox *tshirt_box;
    QLabel *label_10;
    QLineEdit *shift_line;
    QLabel *label_11;
    QLineEdit *submitted_by_line;
    QLineEdit *event_line;
    QLabel *label_7;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(OptionsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        host_line = new QLineEdit(groupBox);
        host_line->setObjectName(QString::fromUtf8("host_line"));

        formLayout->setWidget(0, QFormLayout::FieldRole, host_line);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        user_line = new QLineEdit(groupBox);
        user_line->setObjectName(QString::fromUtf8("user_line"));

        formLayout->setWidget(1, QFormLayout::FieldRole, user_line);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        password_line = new QLineEdit(groupBox);
        password_line->setObjectName(QString::fromUtf8("password_line"));
        password_line->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, password_line);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        database_line = new QLineEdit(groupBox);
        database_line->setObjectName(QString::fromUtf8("database_line"));

        formLayout->setWidget(3, QFormLayout::FieldRole, database_line);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        port_line = new QLineEdit(groupBox);
        port_line->setObjectName(QString::fromUtf8("port_line"));

        formLayout->setWidget(4, QFormLayout::FieldRole, port_line);


        verticalLayout_3->addWidget(groupBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        semester_line = new QLineEdit(groupBox_2);
        semester_line->setObjectName(QString::fromUtf8("semester_line"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, semester_line);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        hours_per_person_line = new QLineEdit(groupBox_2);
        hours_per_person_line->setObjectName(QString::fromUtf8("hours_per_person_line"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, hours_per_person_line);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_9);

        tshirt_box = new QCheckBox(groupBox_2);
        tshirt_box->setObjectName(QString::fromUtf8("tshirt_box"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, tshirt_box);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_10);

        shift_line = new QLineEdit(groupBox_2);
        shift_line->setObjectName(QString::fromUtf8("shift_line"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, shift_line);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_11);

        submitted_by_line = new QLineEdit(groupBox_2);
        submitted_by_line->setObjectName(QString::fromUtf8("submitted_by_line"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, submitted_by_line);

        event_line = new QLineEdit(groupBox_2);
        event_line->setObjectName(QString::fromUtf8("event_line"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, event_line);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);


        verticalLayout_2->addWidget(groupBox_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OptionsDialog", "Database Settings (MySQL)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionsDialog", "Host Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OptionsDialog", "User Name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OptionsDialog", "Password:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OptionsDialog", "Database Name:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OptionsDialog", "Port:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("OptionsDialog", "Database", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("OptionsDialog", "AGS Settings", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("OptionsDialog", "Semester ID:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("OptionsDialog", "Event Hours Per Person:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("OptionsDialog", "AGS T-Shirt Calculator:", 0, QApplication::UnicodeUTF8));
        tshirt_box->setText(QApplication::translate("OptionsDialog", "Check to Enable", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("OptionsDialog", "Shift ID:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("OptionsDialog", "Submitted_by ID:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("OptionsDialog", "Event ID:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("OptionsDialog", "AGS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
