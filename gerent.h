#ifndef GERENT_H
#define GERENT_H

#include <QDialog>

namespace Ui {
class gerent;
}

class gerent : public QDialog
{
    Q_OBJECT

public:
    explicit gerent(QWidget *parent = nullptr);
    ~gerent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gerent *ui;
};

#endif // GERENT_H
