//This program is created by Zhu Zengliang.
#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include <QIntValidator>
#include <QKeyEvent>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();
    QString getSno();
    QString getSname();
    QString getScourse();
    int getSscore();

private:
    Ui::DialogAdd *ui;

private slots:
    void onName();
    void onCourse();
    void onScore();
    void onButton();
protected:
    void keyPressEvent(QKeyEvent *);
};

#endif // DIALOGADD_H
