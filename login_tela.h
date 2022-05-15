#ifndef LOGIN_TELA_H
#define LOGIN_TELA_H

#include <QMainWindow>

namespace Ui {
class login_tela;
}

class login_tela : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_tela(QWidget *parent = nullptr);
    ~login_tela();

private slots:

    void on_pushButton_clicked();

private:
    Ui::login_tela *ui;
};

#endif // LOGIN_TELA_H
