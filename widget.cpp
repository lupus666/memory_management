#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    pro(new progress())
{
    ui->setupUi(this);
    Instruction* ins_array = pro->getAllInsVec();
    for(int i = 0; i < 320; i++){
        Instruction temp = ins_array[i];
        QString str_temp = temp.content;
        QString address = QString::number(temp.current_address);
        QString next = QString::number(temp.next_address);
        str_temp = address + ": " + str_temp + " " + next;
        ui->INSTRUCTION_LIST->append(str_temp);
    }
    ALGORITHM = FIFO;
    ui->INSTRUCTION_LIST->moveCursor(QTextCursor::Start);
    ui->algorithm_display->setText(Algorithm_array[ALGORITHM]);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update()
{
    ui->pagefaultdisplay->setNum(int(pro->getPageFault()));
    ui->ratedisplay->setNum(double(pro->getPageFault())/double(pro->getRunTimes()));
    ui->page_display->setNum(int(pro->getMemoryOffset()));
    ui->page_offset->setNum(int(pro->getPageOffset()));
    ui->algorithm_display->setText(Algorithm_array[ALGORITHM]);
    ui->Page0->moveCursor(QTextCursor::Start);
    ui->Page1->moveCursor(QTextCursor::Start);
    ui->Page2->moveCursor(QTextCursor::Start);
    ui->Page3->moveCursor(QTextCursor::Start);
}

void Widget::on_new_2_clicked()
{
    ui->Page0->clear();
    ui->Page1->clear();
    ui->Page2->clear();
    ui->Page3->clear();
    ui->INSTRUCTION_LIST->clear();
    ui->page_display->clear();
    ui->page_offset->clear();
    ui->pagefaultdisplay->setNum(0);
    ui->ratedisplay->setNum(0);
    ui->Current_INs->clear();


    delete pro;
    pro = new progress();
    Instruction* ins_array = pro->getAllInsVec();
    for(int i = 0; i < 320; i++){
        Instruction temp = ins_array[i];
        QString str_temp = temp.content;
        QString address = QString::number(temp.current_address);
        QString next = QString::number(temp.next_address);
        str_temp = address + ": " + str_temp + " " + next;
        ui->INSTRUCTION_LIST->append(str_temp);
    }
    ui->INSTRUCTION_LIST->moveCursor(QTextCursor::Start);
    ui->single_step->setEnabled(true);
    ui->s->setEnabled(true);

}

void Widget::on_single_step_clicked()
{
    ui->Current_INs->setNum(int(pro->getCurrentIns()));
    if(pro->single_run(ALGORITHM) == -1){
        update();
    }
    else{
        CPage* ins_array = pro->getMemoryVec();
        unsigned memory_offset = pro->getMemoryOffset();

        switch (memory_offset) {
        case 0:
            ui->Page0->clear();
            break;
        case 1:
            ui->Page1->clear();
            break;
        case 2:
            ui->Page2->clear();
            break;
        case 3:
            ui->Page3->clear();
            break;
        default:
            break;
        }
        for(int i = 0; i < 10; i++){
            Instruction temp = ins_array[memory_offset][i];
            QString str_temp = temp.content;
            QString address = QString::number(temp.current_address);
            QString next = QString::number(temp.next_address);
            str_temp = address + ": " + str_temp + " " + next;

            switch (memory_offset) {
            case 0:
                ui->Page0->append(str_temp);
                break;
            case 1:
                ui->Page1->append(str_temp);
                break;
            case 2:
                ui->Page2->append(str_temp);
                break;
            case 3:
                ui->Page3->append(str_temp);
                break;
            default:
                break;
            }
        }
        update();
    }
}

void Widget::on_FIFO_clicked(bool checked)
{
    if(checked == true){
        ALGORITHM = FIFO;
    }
    ui->algorithm_display->setText(Algorithm_array[ALGORITHM]);
}

void Widget::on_LRU_clicked(bool checked)
{
    if(checked == true){
        ALGORITHM = LRU;
    }
    ui->algorithm_display->setText(Algorithm_array[ALGORITHM]);
}

void Widget::on_s_clicked()
{
    for(int i = pro->getRunTimes();i<320;i++){
        on_single_step_clicked();
    }
    ui->single_step->setEnabled(false);
    ui->s->setEnabled(false);
}

void Widget::on_LRU_2_clicked(bool checked)
{
    if(checked == true){
        ALGORITHM = RAND;
    }
    ui->algorithm_display->setText(Algorithm_array[ALGORITHM]);
}

void Widget::on_new_3_clicked()
{
    ui->Page0->clear();
    ui->Page1->clear();
    ui->Page2->clear();
    ui->Page3->clear();
    ui->page_display->clear();
    ui->page_offset->clear();
    ui->pagefaultdisplay->setNum(0);
    ui->ratedisplay->setNum(0);
    ui->Current_INs->clear();
    ui->single_step->setEnabled(true);
    ui->s->setEnabled(true);
    pro->clear_memory();
}
