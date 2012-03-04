/********************************************************************************
** Form generated from reading UI file 'passworddialog.ui'
**
** Created: Sat Mar 3 19:21:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDDIALOG_H
#define UI_PASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *validate_button;
    QLabel *label;
    QLineEdit *username_line;
    QLabel *label_2;
    QLineEdit *password_line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QFrame *line;
    QLabel *label_3;
    QLineEdit *nu_line;
    QLabel *label_4;
    QLineEdit *np_line;
    QLabel *label_5;
    QLineEdit *validate_np_line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PasswordDialog)
    {
        if (PasswordDialog->objectName().isEmpty())
            PasswordDialog->setObjectName(QString::fromUtf8("PasswordDialog"));
        PasswordDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(PasswordDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        groupBox = new QGroupBox(PasswordDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        validate_button = new QPushButton(groupBox);
        validate_button->setObjectName(QString::fromUtf8("validate_button"));

        gridLayout_2->addWidget(validate_button, 2, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        username_line = new QLineEdit(groupBox);
        username_line->setObjectName(QString::fromUtf8("username_line"));

        gridLayout_2->addWidget(username_line, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        password_line = new QLineEdit(groupBox);
        password_line->setObjectName(QString::fromUtf8("password_line"));

        gridLayout_2->addWidget(password_line, 1, 1, 1, 2);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);


        gridLayout_2->addWidget(widget, 3, 0, 2, 3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);

        nu_line = new QLineEdit(groupBox);
        nu_line->setObjectName(QString::fromUtf8("nu_line"));

        gridLayout_2->addWidget(nu_line, 5, 1, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        np_line = new QLineEdit(groupBox);
        np_line->setObjectName(QString::fromUtf8("np_line"));

        gridLayout_2->addWidget(np_line, 6, 1, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 7, 0, 1, 1);

        validate_np_line = new QLineEdit(groupBox);
        validate_np_line->setObjectName(QString::fromUtf8("validate_np_line"));

        gridLayout_2->addWidget(validate_np_line, 7, 1, 1, 2);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(PasswordDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(username_line);
        label_2->setBuddy(password_line);
        label_3->setBuddy(nu_line);
        label_4->setBuddy(np_line);
        label_5->setBuddy(validate_np_line);
#endif // QT_NO_SHORTCUT

        retranslateUi(PasswordDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PasswordDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PasswordDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *PasswordDialog)
    {
        PasswordDialog->setWindowTitle(QApplication::translate("PasswordDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PasswordDialog", "Update Username/Password", 0, QApplication::UnicodeUTF8));
        validate_button->setText(QApplication::translate("PasswordDialog", "Validate", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PasswordDialog", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PasswordDialog", "Password", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PasswordDialog", "New Username", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nu_line->setToolTip(QApplication::translate("PasswordDialog", "Leave blank to keep the same Username", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("PasswordDialog", "New Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        np_line->setToolTip(QApplication::translate("PasswordDialog", "Leave this and the next line blank to keep the same password", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("PasswordDialog", "Verify New Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        validate_np_line->setToolTip(QApplication::translate("PasswordDialog", "Leave this and the previous line blank to keep the same password", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        validate_np_line->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class PasswordDialog: public Ui_PasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDDIALOG_H
