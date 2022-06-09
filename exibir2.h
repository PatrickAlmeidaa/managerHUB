#ifndef EXIBIR2_H
#define EXIBIR2_H

#include <QDialog>

#include <QtSql>
#include <QMessageBox>
#include <QAbstractItemView>

namespace Ui {
class exibir2;
}

class exibir2 : public QDialog
{
    Q_OBJECT

public:
    explicit exibir2(QWidget *parent = nullptr);
    ~exibir2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::exibir2 *ui;
};

#endif // EXIBIR2_H
