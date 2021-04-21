//This program is created by Zhu Zengliang.
#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_buttomAdd_triggered()
{
    DialogAdd*dialog=new DialogAdd(this);
    int ret=dialog->exec();//return value,show the dialog
    if(ret==QDialog::Accepted)
    {
        this->sNo=dialog->getSno();
        this->sName=dialog->getSname();
        this->sCourse=dialog->getScourse();
        this->sScore=dialog->getSscore();
        //ui->textBrowser->setText(sNo+" "+sName+" "+sCourse+" "+QString::number(sScore));
        QSqlQuery query(db);
        query.exec(QString("      ")
                   .arg(dialog->getSno()).arg(dialog->getSname())
                   .arg(dialog->getScourse()).arg(dialog->getSscore())
                   );
  /*      if(query.isActive()){
            ui->textBrowser->setHtml("""<div style='color:green;'>&gt;Insertion successful!</div>""");
        }
        else
        {
            ui->textBrowser->setHtml("""<div style='color:red;'>&gt;Insertion failed!</div>""");
        }
     */
    }

    on_Button_show_clicked();
    delete dialog;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button_add,&QPushButton::clicked,this,&MainWindow::on_buttomAdd_triggered);
    qDebug() << QSqlDatabase::drivers();
    this->db=QSqlDatabase::addDatabase("QMYSQL");//添加数据库
    db.setHostName("127.0.0.1"); //数据库服务器IP 端口默认是3236

    db.setUserName("root"); //数据库用户名

    db.setPassword("12345"); //密码

    db.setDatabaseName("stu_sys"); //使用哪个数据库，mysql中创建的数据库

    //打开数据库

    if( !db.open() ) //数据库打开失败

    {//如果没有在项目中加入mysql的库(需要自己去下载然后添加，比如window的libmysql.dll)，就会提示驱动没有加载的错误

        QMessageBox::warning(this, "错误", db.lastError().text());//此时需要，数据库库文件(libmysql.dll)需要放到qt的安装目录里面的bin目录下

        return;

    }else
    {
        ui->textBrowser->append(" ");
    }

    QSqlQuery query(db);

    query.exec("      ");
    ui->textBrowser->append(">Created table: student\n>System is ready!\n");



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Button_show_clicked()
{
    QSqlQuery query(db);
    query.exec("select * from student");
    ui->textBrowser->setText("====================================");
    while(query.next())
    {
        ui->textBrowser->settext(query.value("sNo").toString()+"\t"+query.value("sName").toString()+"\t"+query.value("sCourse").toString()+"\t"+query.value("sScore").toString());
    }
    ui->textBrowser->append("====================================");
}

void MainWindow::on_Button_drop_clicked()
{
    DialogDrop*dialog=new DialogDrop(this);
    dialog->init_combo(db);
    int ret=dialog->exec();//return value,show the dialog
    if(ret==QDialog::Accepted)
    {
        QSqlQuery query(db);
        QString no=dialog->getComboNO();
        QString course=dialog->getComboCourse();
        qDebug()<<no<<course;
        query.exec(     );
    }
    delete dialog;
    on_Button_show_clicked();
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query(db);
    query.exec("select a.no,a.name,max(a.score) from(select sNo,sName,avg(sScore) from student group by sNo order by avg(sScore) desc)as a(no,name,score);");
    ui->textBrowser->setText("--------------------------------------------------");
    while(query.next())
    {
        ui->textBrowser->settext(query.value(0).toString()+"\t"+query.value(1).toString()+"\t"+"average: "+query.value(2).toString());
    }
    ui->textBrowser->append("--------------------------------------------------");

}
