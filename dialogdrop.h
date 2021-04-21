//This program is created by Zhu Zengliang.
#ifndef DIALOGDROP_H
#define DIALOGDROP_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QList>
#include <QString>
namespace Ui {
class DialogDrop;
}

class DialogDrop : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDrop(QWidget *parent = nullptr);
    ~DialogDrop();
    void init_combo(QSqlDatabase &db);
    QString getComboNO();
    QString getComboCourse();

private:
    Ui::DialogDrop *ui;
};

#endif // DIALOGDROP_H
