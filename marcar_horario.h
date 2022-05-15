#ifndef MARCAR_HORARIO_H
#define MARCAR_HORARIO_H

#include <QDialog>

namespace Ui {
class Marcar_Horario;
}

class Marcar_Horario : public QDialog
{
    Q_OBJECT

public:
    explicit Marcar_Horario(QWidget *parent = nullptr);
    ~Marcar_Horario();

private slots:
    void on_pushButton_2_clicked();

    void on_Agendar_clicked();

private:
    Ui::Marcar_Horario *ui;
};

#endif // MARCAR_HORARIO_H
