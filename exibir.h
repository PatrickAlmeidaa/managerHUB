#ifndef EXIBIR_H
#define EXIBIR_H

#include <QDialog>
#include "marcar_horario.h"
#include "gerent.h"

#include <QtSql>
#include <QMessageBox>
#include <QAbstractItemView>

namespace Ui {
class exibir;
}

class exibir : public QDialog
{
    Q_OBJECT

public:
    explicit exibir(QWidget *parent = nullptr);
    ~exibir();
private slots:
    void on_pushButton_clicked();

private:
    Ui::exibir *ui;
};

#endif // EXIBIR_H
