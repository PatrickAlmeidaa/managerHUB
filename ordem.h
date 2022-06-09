#ifndef ORDEM_H
#define ORDEM_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>

namespace Ui {
class ordem;
}

class ordem : public QDialog
{
    Q_OBJECT

public:
    explicit ordem(QWidget *parent = nullptr);
    ~ordem();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ordem *ui;
};

#endif // ORDEM_H
