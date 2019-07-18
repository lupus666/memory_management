/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *Instruction_List;
    QLabel *label_5;
    QTextEdit *INSTRUCTION_LIST;
    QWidget *layoutWidget1;
    QVBoxLayout *MEMORY;
    QLabel *label;
    QVBoxLayout *MEMORY_2;
    QHBoxLayout *PAGE_4;
    QTextEdit *Page0;
    QLabel *page0_label;
    QHBoxLayout *PAGE_1;
    QTextEdit *Page1;
    QLabel *page1_label;
    QHBoxLayout *PAGE_2;
    QTextEdit *Page2;
    QLabel *page2_label;
    QHBoxLayout *PAGE_3;
    QTextEdit *Page3;
    QLabel *page3_label;
    QWidget *layoutWidget2;
    QVBoxLayout *INFO_1;
    QHBoxLayout *PAGE_FAULT;
    QLabel *label_6;
    QLabel *pagefaultdisplay;
    QHBoxLayout *PAGE_FAULT_RATE;
    QLabel *label_8;
    QLabel *ratedisplay;
    QHBoxLayout *PAGE_NO;
    QLabel *label_11;
    QLabel *page_display;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *PAGE_OFFSET;
    QLabel *label_13;
    QLabel *page_offset;
    QWidget *layoutWidget3;
    QVBoxLayout *OPERATION;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout;
    QPushButton *new_2;
    QPushButton *new_3;
    QPushButton *single_step;
    QPushButton *s;
    QWidget *layoutWidget4;
    QHBoxLayout *Algorithms_selector;
    QLabel *algorithm;
    QRadioButton *FIFO;
    QRadioButton *LRU;
    QRadioButton *LRU_2;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *algorithm_label;
    QLabel *algorithm_display;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *Current_INs;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(560, 70, 211, 251));
        Instruction_List = new QVBoxLayout(layoutWidget);
        Instruction_List->setSpacing(6);
        Instruction_List->setContentsMargins(11, 11, 11, 11);
        Instruction_List->setObjectName(QString::fromUtf8("Instruction_List"));
        Instruction_List->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        Instruction_List->addWidget(label_5);

        INSTRUCTION_LIST = new QTextEdit(layoutWidget);
        INSTRUCTION_LIST->setObjectName(QString::fromUtf8("INSTRUCTION_LIST"));
        INSTRUCTION_LIST->setReadOnly(true);

        Instruction_List->addWidget(INSTRUCTION_LIST);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 70, 211, 431));
        MEMORY = new QVBoxLayout(layoutWidget1);
        MEMORY->setSpacing(6);
        MEMORY->setContentsMargins(11, 11, 11, 11);
        MEMORY->setObjectName(QString::fromUtf8("MEMORY"));
        MEMORY->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        MEMORY->addWidget(label);

        MEMORY_2 = new QVBoxLayout();
        MEMORY_2->setSpacing(6);
        MEMORY_2->setObjectName(QString::fromUtf8("MEMORY_2"));
        PAGE_4 = new QHBoxLayout();
        PAGE_4->setSpacing(6);
        PAGE_4->setObjectName(QString::fromUtf8("PAGE_4"));
        Page0 = new QTextEdit(layoutWidget1);
        Page0->setObjectName(QString::fromUtf8("Page0"));
        Page0->setReadOnly(true);

        PAGE_4->addWidget(Page0);

        page0_label = new QLabel(layoutWidget1);
        page0_label->setObjectName(QString::fromUtf8("page0_label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        page0_label->setFont(font1);

        PAGE_4->addWidget(page0_label);


        MEMORY_2->addLayout(PAGE_4);

        PAGE_1 = new QHBoxLayout();
        PAGE_1->setSpacing(6);
        PAGE_1->setObjectName(QString::fromUtf8("PAGE_1"));
        Page1 = new QTextEdit(layoutWidget1);
        Page1->setObjectName(QString::fromUtf8("Page1"));
        Page1->setReadOnly(true);

        PAGE_1->addWidget(Page1);

        page1_label = new QLabel(layoutWidget1);
        page1_label->setObjectName(QString::fromUtf8("page1_label"));
        page1_label->setFont(font1);

        PAGE_1->addWidget(page1_label);


        MEMORY_2->addLayout(PAGE_1);

        PAGE_2 = new QHBoxLayout();
        PAGE_2->setSpacing(6);
        PAGE_2->setObjectName(QString::fromUtf8("PAGE_2"));
        Page2 = new QTextEdit(layoutWidget1);
        Page2->setObjectName(QString::fromUtf8("Page2"));
        Page2->setReadOnly(true);

        PAGE_2->addWidget(Page2);

        page2_label = new QLabel(layoutWidget1);
        page2_label->setObjectName(QString::fromUtf8("page2_label"));
        page2_label->setFont(font1);

        PAGE_2->addWidget(page2_label);


        MEMORY_2->addLayout(PAGE_2);

        PAGE_3 = new QHBoxLayout();
        PAGE_3->setSpacing(6);
        PAGE_3->setObjectName(QString::fromUtf8("PAGE_3"));
        Page3 = new QTextEdit(layoutWidget1);
        Page3->setObjectName(QString::fromUtf8("Page3"));
        Page3->setReadOnly(true);

        PAGE_3->addWidget(Page3);

        page3_label = new QLabel(layoutWidget1);
        page3_label->setObjectName(QString::fromUtf8("page3_label"));
        page3_label->setFont(font1);

        PAGE_3->addWidget(page3_label);


        MEMORY_2->addLayout(PAGE_3);


        MEMORY->addLayout(MEMORY_2);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(266, 150, 281, 161));
        INFO_1 = new QVBoxLayout(layoutWidget2);
        INFO_1->setSpacing(6);
        INFO_1->setContentsMargins(11, 11, 11, 11);
        INFO_1->setObjectName(QString::fromUtf8("INFO_1"));
        INFO_1->setContentsMargins(0, 0, 0, 0);
        PAGE_FAULT = new QHBoxLayout();
        PAGE_FAULT->setSpacing(6);
        PAGE_FAULT->setObjectName(QString::fromUtf8("PAGE_FAULT"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        PAGE_FAULT->addWidget(label_6);

        pagefaultdisplay = new QLabel(layoutWidget2);
        pagefaultdisplay->setObjectName(QString::fromUtf8("pagefaultdisplay"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(14);
        pagefaultdisplay->setFont(font2);

        PAGE_FAULT->addWidget(pagefaultdisplay);


        INFO_1->addLayout(PAGE_FAULT);

        PAGE_FAULT_RATE = new QHBoxLayout();
        PAGE_FAULT_RATE->setSpacing(6);
        PAGE_FAULT_RATE->setObjectName(QString::fromUtf8("PAGE_FAULT_RATE"));
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        PAGE_FAULT_RATE->addWidget(label_8);

        ratedisplay = new QLabel(layoutWidget2);
        ratedisplay->setObjectName(QString::fromUtf8("ratedisplay"));
        ratedisplay->setFont(font2);

        PAGE_FAULT_RATE->addWidget(ratedisplay);


        INFO_1->addLayout(PAGE_FAULT_RATE);

        PAGE_NO = new QHBoxLayout();
        PAGE_NO->setSpacing(6);
        PAGE_NO->setObjectName(QString::fromUtf8("PAGE_NO"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        PAGE_NO->addWidget(label_11);

        page_display = new QLabel(layoutWidget2);
        page_display->setObjectName(QString::fromUtf8("page_display"));
        page_display->setFont(font2);

        PAGE_NO->addWidget(page_display);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PAGE_NO->addItem(horizontalSpacer);


        INFO_1->addLayout(PAGE_NO);

        PAGE_OFFSET = new QHBoxLayout();
        PAGE_OFFSET->setSpacing(6);
        PAGE_OFFSET->setObjectName(QString::fromUtf8("PAGE_OFFSET"));
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        PAGE_OFFSET->addWidget(label_13);

        page_offset = new QLabel(layoutWidget2);
        page_offset->setObjectName(QString::fromUtf8("page_offset"));
        page_offset->setFont(font2);

        PAGE_OFFSET->addWidget(page_offset);


        INFO_1->addLayout(PAGE_OFFSET);

        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(250, 410, 541, 71));
        OPERATION = new QVBoxLayout(layoutWidget3);
        OPERATION->setSpacing(6);
        OPERATION->setContentsMargins(11, 11, 11, 11);
        OPERATION->setObjectName(QString::fromUtf8("OPERATION"));
        OPERATION->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        OPERATION->addWidget(label_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        new_2 = new QPushButton(layoutWidget3);
        new_2->setObjectName(QString::fromUtf8("new_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        new_2->setFont(font3);

        horizontalLayout->addWidget(new_2);

        new_3 = new QPushButton(layoutWidget3);
        new_3->setObjectName(QString::fromUtf8("new_3"));
        new_3->setFont(font3);

        horizontalLayout->addWidget(new_3);

        single_step = new QPushButton(layoutWidget3);
        single_step->setObjectName(QString::fromUtf8("single_step"));
        single_step->setFont(font2);

        horizontalLayout->addWidget(single_step);

        s = new QPushButton(layoutWidget3);
        s->setObjectName(QString::fromUtf8("s"));
        s->setFont(font2);

        horizontalLayout->addWidget(s);


        OPERATION->addLayout(horizontalLayout);

        layoutWidget4 = new QWidget(Widget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(32, 12, 381, 41));
        Algorithms_selector = new QHBoxLayout(layoutWidget4);
        Algorithms_selector->setSpacing(6);
        Algorithms_selector->setContentsMargins(11, 11, 11, 11);
        Algorithms_selector->setObjectName(QString::fromUtf8("Algorithms_selector"));
        Algorithms_selector->setContentsMargins(0, 0, 0, 0);
        algorithm = new QLabel(layoutWidget4);
        algorithm->setObjectName(QString::fromUtf8("algorithm"));
        algorithm->setFont(font);

        Algorithms_selector->addWidget(algorithm);

        FIFO = new QRadioButton(layoutWidget4);
        FIFO->setObjectName(QString::fromUtf8("FIFO"));
        FIFO->setCheckable(true);
        FIFO->setChecked(false);

        Algorithms_selector->addWidget(FIFO);

        LRU = new QRadioButton(layoutWidget4);
        LRU->setObjectName(QString::fromUtf8("LRU"));

        Algorithms_selector->addWidget(LRU);

        LRU_2 = new QRadioButton(layoutWidget4);
        LRU_2->setObjectName(QString::fromUtf8("LRU_2"));

        Algorithms_selector->addWidget(LRU_2);

        layoutWidget5 = new QWidget(Widget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(290, 70, 245, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        algorithm_label = new QLabel(layoutWidget5);
        algorithm_label->setObjectName(QString::fromUtf8("algorithm_label"));
        algorithm_label->setFont(font);

        horizontalLayout_2->addWidget(algorithm_label);

        algorithm_display = new QLabel(layoutWidget5);
        algorithm_display->setObjectName(QString::fromUtf8("algorithm_display"));
        algorithm_display->setFont(font);

        horizontalLayout_2->addWidget(algorithm_display);

        layoutWidget6 = new QWidget(Widget);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(270, 330, 261, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        Current_INs = new QLabel(layoutWidget6);
        Current_INs->setObjectName(QString::fromUtf8("Current_INs"));
        Current_INs->setFont(font2);

        horizontalLayout_3->addWidget(Current_INs);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_5->setText(QApplication::translate("Widget", "     Instruction List", nullptr));
        INSTRUCTION_LIST->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QApplication::translate("Widget", "         Memory", nullptr));
        Page0->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        page0_label->setText(QApplication::translate("Widget", "Page 0", nullptr));
        Page1->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        page1_label->setText(QApplication::translate("Widget", "Page 1", nullptr));
        Page2->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        page2_label->setText(QApplication::translate("Widget", "Page 2", nullptr));
        Page3->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        page3_label->setText(QApplication::translate("Widget", "Page 3", nullptr));
        label_6->setText(QApplication::translate("Widget", "PAGE FAULT=", nullptr));
        pagefaultdisplay->setText(QApplication::translate("Widget", "0", nullptr));
        label_8->setText(QApplication::translate("Widget", "PAGE FAULT RATE=", nullptr));
        ratedisplay->setText(QApplication::translate("Widget", "0", nullptr));
        label_11->setText(QApplication::translate("Widget", "PAGE=", nullptr));
        page_display->setText(QString());
        label_13->setText(QApplication::translate("Widget", "PAGE OFFSET=", nullptr));
        page_offset->setText(QString());
        label_10->setText(QApplication::translate("Widget", "                        OPERATION", nullptr));
        new_2->setText(QApplication::translate("Widget", "NEW", nullptr));
        new_3->setText(QApplication::translate("Widget", "Clear", nullptr));
        single_step->setText(QApplication::translate("Widget", "SINGLE STEP", nullptr));
        s->setText(QApplication::translate("Widget", "SEQUENTIAL EXECUTION", nullptr));
        algorithm->setText(QApplication::translate("Widget", "Algorithm", nullptr));
        FIFO->setText(QApplication::translate("Widget", "FIFO", nullptr));
        LRU->setText(QApplication::translate("Widget", "LRU", nullptr));
        LRU_2->setText(QApplication::translate("Widget", "RAND", nullptr));
        algorithm_label->setText(QApplication::translate("Widget", "ALGORITHM = ", nullptr));
        algorithm_display->setText(QString());
        label_2->setText(QApplication::translate("Widget", "Current Instruction =", nullptr));
        Current_INs->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
