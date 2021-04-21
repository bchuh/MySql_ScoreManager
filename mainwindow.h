//This program is created by Zhu Zengliang.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialogadd.h>
#include <dialogdrop.h>

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void on_buttomAdd_triggered();
    void on_Button_show_clicked();

    void on_Button_drop_clicked();

    void on_pushButton_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;

private:
    Ui::MainWindow *ui;

    QString sNo;
    QString sName;
    QString sCourse;
    int sScore;
};
#endif // MAINWINDOW_H
