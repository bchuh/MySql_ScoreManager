//This program is created by Zhu Zengliang.
#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
    ui->D_sscore->setValidator(new QIntValidator(0,100,this));
    ui->D_sno->setFocus();
    connect(ui->D_sno,&QLineEdit::returnPressed,this,&DialogAdd::onName);
    connect(ui->D_sname,&QLineEdit::returnPressed,this,&DialogAdd::onCourse);
    connect(ui->D_scourse,&QLineEdit::returnPressed,this,&DialogAdd::onScore);
    connect(ui->D_sscore,&QLineEdit::returnPressed,this,&DialogAdd::onButton);
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

QString DialogAdd::getSno()
{
    return ui->D_sno->text();
}

QString DialogAdd::getSname()
{
    return ui->D_sname->text();
}

QString DialogAdd::getScourse()
{
    return ui->D_scourse->text();
}

int DialogAdd::getSscore()
{
    return ui->D_sscore->text().toInt();
}

void DialogAdd::onName()
{
    ui->D_sname->setFocus();

}

void DialogAdd::onCourse()
{
    ui->D_scourse->setFocus();
}

void DialogAdd::onScore()
{
    ui->D_sscore->setFocus();
}

void DialogAdd::onButton()
{
    ui->buttonBox->setFocus();
}

void DialogAdd::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)
        return;
    QDialog::keyPressEvent(event);
}



