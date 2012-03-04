/********************************************************************************
** Form generated from reading UI file 'passworddialog.ui'
**
** Created: Sun Mar 4 00:49:06 2012
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
    QLabel *username_label;
    QLineEdit *username_line;
    QLabel *password_label;
    QLineEdit *password_line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QFrame *line;
    QLabel *nu_label;
    QLineEdit *nu_line;
    QLabel *np_label;
    QLineEdit *np_line;
    QLabel *verify_np_label;
    QLineEdit *verify_np_line;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_button;
    QPushButton *cancel_button;

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

        username_label = new QLabel(groupBox);
        username_label->setObjectName(QString::fromUtf8("username_label"));

        gridLayout_2->addWidget(username_label, 0, 0, 1, 1);

        username_line = new QLineEdit(groupBox);
        username_line->setObjectName(QString::fromUtf8("username_line"));

        gridLayout_2->addWidget(username_line, 0, 1, 1, 2);

        password_label = new QLabel(groupBox);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        gridLayout_2->addWidget(password_label, 1, 0, 1, 1);

        password_line = new QLineEdit(groupBox);
        password_line->setObjectName(QString::fromUtf8("password_line"));
        password_line->setEchoMode(QLineEdit::Password);

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

        nu_label = new QLabel(groupBox);
        nu_label->setObjectName(QString::fromUtf8("nu_label"));

        gridLayout_2->addWidget(nu_label, 5, 0, 1, 1);

        nu_line = new QLineEdit(groupBox);
        nu_line->setObjectName(QString::fromUtf8("nu_line"));

        gridLayout_2->addWidget(nu_line, 5, 1, 1, 2);

        np_label = new QLabel(groupBox);
        np_label->setObjectName(QString::fromUtf8("np_label"));

        gridLayout_2->addWidget(np_label, 6, 0, 1, 1);

        np_line = new QLineEdit(groupBox);
        np_line->setObjectName(QString::fromUtf8("np_line"));
        np_line->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(np_line, 6, 1, 1, 2);

        verify_np_label = new QLabel(groupBox);
        verify_np_label->setObjectName(QString::fromUtf8("verify_np_label"));

        gridLayout_2->addWidget(verify_np_label, 7, 0, 1, 1);

        verify_np_line = new QLineEdit(groupBox);
        verify_np_line->setObjectName(QString::fromUtf8("verify_np_line"));
        verify_np_line->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(verify_np_line, 7, 1, 1, 2);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ok_button = new QPushButton(PasswordDialog);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));

        horizontalLayout_2->addWidget(ok_button);

        cancel_button = new QPushButton(PasswordDialog);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));

        horizontalLayout_2->addWidget(cancel_button);


        verticalLayout->addLayout(horizontalLayout_2);

#ifndef QT_NO_SHORTCUT
        username_label->setBuddy(username_line);
        password_label->setBuddy(password_line);
        nu_label->setBuddy(nu_line);
        np_label->setBuddy(np_line);
        verify_np_label->setBuddy(verify_np_line);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(username_line, password_line);
        QWidget::setTabOrder(password_line, validate_button);
        QWidget::setTabOrder(validate_button, nu_line);
        QWidget::setTabOrder(nu_line, np_line);
        QWidget::setTabOrder(np_line, verify_np_line);
        QWidget::setTabOrder(verify_np_line, ok_button);
        QWidget::setTabOrder(ok_button, cancel_button);

        retranslateUi(PasswordDialog);
        QObject::connect(ok_button, SIGNAL(clicked()), PasswordDialog, SLOT(accept()));
        QObject::connect(cancel_button, SIGNAL(clicked()), PasswordDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *PasswordDialog)
    {
        PasswordDialog->setWindowTitle(QApplication::translate("PasswordDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PasswordDialog", "Update Username/Password", 0, QApplication::UnicodeUTF8));
        validate_button->setText(QApplication::translate("PasswordDialog", "Validate", 0, QApplication::UnicodeUTF8));
        username_label->setText(QApplication::translate("PasswordDialog", "Username", 0, QApplication::UnicodeUTF8));
        password_label->setText(QApplication::translate("PasswordDialog", "Password", 0, QApplication::UnicodeUTF8));
        nu_label->setText(QApplication::translate("PasswordDialog", "New Username", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nu_line->setToolTip(QApplication::translate("PasswordDialog", "Leave blank to keep the same Username", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        np_label->setText(QApplication::translate("PasswordDialog", "New Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        np_line->setToolTip(QApplication::translate("PasswordDialog", "Leave this and the next line blank to keep the same password", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        verify_np_label->setText(QApplication::translate("PasswordDialog", "Verify New Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        verify_np_line->setToolTip(QApplication::translate("PasswordDialog", "Leave this and the previous line blank to keep the same password", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        verify_np_line->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        ok_button->setText(QApplication::translate("PasswordDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("PasswordDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PasswordDialog: public Ui_PasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDDIALOG_H
