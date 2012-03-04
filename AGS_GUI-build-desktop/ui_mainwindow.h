/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Mar 3 19:21:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExport_log_to;
    QAction *actionExit;
    QAction *actionOptions;
    QAction *actionAGSD;
    QAction *actionCS;
    QAction *actionMeeting;
    QAction *actionOther;
    QAction *actionSocial;
    QAction *actionAbout;
    QAction *actionView_Tutorial;
    QAction *actionReport_a_problem;
    QAction *actionNew;
    QAction *actionOpen;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLineEdit *username_line;
    QLabel *label_8;
    QLineEdit *password_line;
    QPushButton *login_button;
    QLabel *login_message;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QWidget *log_page;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *pcc_id_line;
    QLabel *label_2;
    QLineEdit *ags_id_line;
    QLabel *label_3;
    QLineEdit *first_name_line;
    QLabel *label_4;
    QLineEdit *last_name_line;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *event_label;
    QLineEdit *time_stamp_line;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *file_name;
    QTextEdit *textEdit;
    QWidget *unopen_page;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_9;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuChange_Event;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(723, 581);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralWidget, #login_page, #log_page, #unopen_page{\n"
"	background-color: rgb(171,32,25);}\n"
"QFrame#frame_2 QLabel, #login_page QLabel, #unopen_page QLabel{\n"
"	color: rgb(250, 195, 6);}\n"
"QFrame#frame_2 QLineEdit, #login_page QLineEdit{\n"
"	color: white;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(250, 195, 6);\n"
"	background-color: rgb(128, 0, 0);}\n"
"QWidget#frame_2 *, #login_page *, #unopen_page *{\n"
"	font: 150 20pt \"Times New Roman\";}\n"
"#login_button{\n"
"	border-style:solid;\n"
"	border-width: 2px;\n"
"	border-radius: 20px;\n"
"	border-color: rgb(250, 195, 6);\n"
"	background-color: rgb(128, 0, 0);\n"
"	color: rgb(250, 195, 6);}\n"
"#login_button:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(237, 12, 12, 255), stop:0.409091 rgba(237, 12, 12, 255), stop:0.5 rgba(231, 4, 4, 255), stop:1 rgba(128, 0, 0, 255));\n"
"}\n"
"\n"
"#login_button:pressed{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0"
                        ", y2:1, stop:0 rgba(128, 0, 0, 255), stop:0.403409 rgba(231, 4, 4, 255), stop:0.505682 rgba(237, 12, 12, 255), stop:1 rgba(237, 12, 12, 255));\n"
"}"));
        actionExport_log_to = new QAction(MainWindow);
        actionExport_log_to->setObjectName(QString::fromUtf8("actionExport_log_to"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionAGSD = new QAction(MainWindow);
        actionAGSD->setObjectName(QString::fromUtf8("actionAGSD"));
        actionCS = new QAction(MainWindow);
        actionCS->setObjectName(QString::fromUtf8("actionCS"));
        actionMeeting = new QAction(MainWindow);
        actionMeeting->setObjectName(QString::fromUtf8("actionMeeting"));
        actionOther = new QAction(MainWindow);
        actionOther->setObjectName(QString::fromUtf8("actionOther"));
        actionSocial = new QAction(MainWindow);
        actionSocial->setObjectName(QString::fromUtf8("actionSocial"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionView_Tutorial = new QAction(MainWindow);
        actionView_Tutorial->setObjectName(QString::fromUtf8("actionView_Tutorial"));
        actionReport_a_problem = new QAction(MainWindow);
        actionReport_a_problem->setObjectName(QString::fromUtf8("actionReport_a_problem"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        login_page = new QWidget();
        login_page->setObjectName(QString::fromUtf8("login_page"));
        gridLayout_3 = new QGridLayout(login_page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_7 = new QLabel(login_page);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        username_line = new QLineEdit(login_page);
        username_line->setObjectName(QString::fromUtf8("username_line"));

        formLayout->setWidget(1, QFormLayout::FieldRole, username_line);

        label_8 = new QLabel(login_page);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        password_line = new QLineEdit(login_page);
        password_line->setObjectName(QString::fromUtf8("password_line"));
        password_line->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, password_line);

        login_button = new QPushButton(login_page);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(3, QFormLayout::SpanningRole, login_button);

        login_message = new QLabel(login_page);
        login_message->setObjectName(QString::fromUtf8("login_message"));
        login_message->setTextFormat(Qt::AutoText);
        login_message->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, login_message);


        gridLayout_3->addLayout(formLayout, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 2, 1, 1, 1);

        stackedWidget->addWidget(login_page);
        log_page = new QWidget();
        log_page->setObjectName(QString::fromUtf8("log_page"));
        verticalLayout_3 = new QVBoxLayout(log_page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(log_page);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(25, 25));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(1);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        pcc_id_line = new QLineEdit(frame_2);
        pcc_id_line->setObjectName(QString::fromUtf8("pcc_id_line"));
        pcc_id_line->setMaxLength(8);

        gridLayout->addWidget(pcc_id_line, 1, 2, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        ags_id_line = new QLineEdit(frame_2);
        ags_id_line->setObjectName(QString::fromUtf8("ags_id_line"));
        ags_id_line->setMaxLength(4);

        gridLayout->addWidget(ags_id_line, 3, 2, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 1, 1, 1);

        first_name_line = new QLineEdit(frame_2);
        first_name_line->setObjectName(QString::fromUtf8("first_name_line"));
        first_name_line->setReadOnly(true);

        gridLayout->addWidget(first_name_line, 5, 2, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 7, 1, 1, 1);

        last_name_line = new QLineEdit(frame_2);
        last_name_line->setObjectName(QString::fromUtf8("last_name_line"));
        last_name_line->setReadOnly(true);

        gridLayout->addWidget(last_name_line, 7, 2, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 9, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 4, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 6, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_4, 8, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 500, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 10, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 2);

        widget = new QWidget(frame_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/images/AGS_LOGO.jpg")));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        event_label = new QLabel(widget);
        event_label->setObjectName(QString::fromUtf8("event_label"));
        event_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(event_label, 1, 1, 1, 3);


        gridLayout->addWidget(widget, 11, 1, 1, 2);

        time_stamp_line = new QLineEdit(frame_2);
        time_stamp_line->setObjectName(QString::fromUtf8("time_stamp_line"));
        time_stamp_line->setReadOnly(true);

        gridLayout->addWidget(time_stamp_line, 9, 2, 1, 1);

        splitter->addWidget(frame_2);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(25, 50));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        file_name = new QLineEdit(frame);
        file_name->setObjectName(QString::fromUtf8("file_name"));
        file_name->setStyleSheet(QString::fromUtf8(""));
        file_name->setReadOnly(true);

        verticalLayout_2->addWidget(file_name);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{\n"
"	background: rgb(171,32,25);}\n"
"\n"
""));
        textEdit->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit);

        splitter->addWidget(frame);

        verticalLayout_3->addWidget(splitter);

        stackedWidget->addWidget(log_page);
        unopen_page = new QWidget();
        unopen_page->setObjectName(QString::fromUtf8("unopen_page"));
        gridLayout_4 = new QGridLayout(unopen_page);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer_8 = new QSpacerItem(20, 190, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_8, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(289, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 1, 0, 1, 1);

        label_9 = new QLabel(unopen_page);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(289, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 1, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 190, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_9, 2, 1, 1, 1);

        stackedWidget->addWidget(unopen_page);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 723, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuChange_Event = new QMenu(menuTools);
        menuChange_Event->setObjectName(QString::fromUtf8("menuChange_Event"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExport_log_to);
        menuFile->addAction(actionExit);
        menuTools->addAction(actionOptions);
        menuTools->addAction(menuChange_Event->menuAction());
        menuChange_Event->addAction(actionAGSD);
        menuChange_Event->addAction(actionCS);
        menuChange_Event->addAction(actionMeeting);
        menuChange_Event->addAction(actionSocial);
        menuChange_Event->addAction(actionOther);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionView_Tutorial);
        menuHelp->addAction(actionReport_a_problem);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExport_log_to->setText(QApplication::translate("MainWindow", "Export log to...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        actionAGSD->setText(QApplication::translate("MainWindow", "AGS", 0, QApplication::UnicodeUTF8));
        actionCS->setText(QApplication::translate("MainWindow", "CS", 0, QApplication::UnicodeUTF8));
        actionMeeting->setText(QApplication::translate("MainWindow", "Meeting", 0, QApplication::UnicodeUTF8));
        actionOther->setText(QApplication::translate("MainWindow", "Other", 0, QApplication::UnicodeUTF8));
        actionSocial->setText(QApplication::translate("MainWindow", "Social", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionView_Tutorial->setText(QApplication::translate("MainWindow", "View Tutorial", 0, QApplication::UnicodeUTF8));
        actionReport_a_problem->setText(QApplication::translate("MainWindow", "Report a problem", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "&New...", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Username:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Password:", 0, QApplication::UnicodeUTF8));
        login_button->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        login_message->setText(QString());
        label->setText(QApplication::translate("MainWindow", "PCC Student ID:", 0, QApplication::UnicodeUTF8));
        pcc_id_line->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "AGS ID:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "First Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Last Name:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Time Stamp:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        event_label->setText(QApplication::translate("MainWindow", "EVENT TYPE, ID", 0, QApplication::UnicodeUTF8));
        time_stamp_line->setText(QApplication::translate("MainWindow", "yyyy-MM-dd_hh-mm-ss", 0, QApplication::UnicodeUTF8));
        file_name->setText(QApplication::translate("MainWindow", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Log Info</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Open or create a new event", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuChange_Event->setTitle(QApplication::translate("MainWindow", "Change Event", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
