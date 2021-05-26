//This program is created by Zhu Zengliang.
#include "dialogdrop.h"
#include "ui_dialogdrop.h"

DialogDrop::DialogDrop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDrop)
{
    ui->setupUi(this);

}

DialogDrop::~DialogDrop()
{
    delete ui;
}

void DialogDrop::init_combo(QSqlDatabase &db)
{
    QSqlQuery query(db);
    query.exec("select * from student");
    while(query.next())
    {

        ui->comboBox->addItem(query.value("sNo").toString()+"\t"+query.value("sName").toString()+"\t"+query.value("sCourse").toString()+"\t"+query.value("sScore").toString()
                              ,query.value("sNo"));


    }

}

QString DialogDrop::getComboNO()
{
    return ui->comboBox->currentText().section('\t',0,0);
}

QString DialogDrop::getComboCourse()
{
    return ui->comboBox->currentText().section('\t',2,2);
}
