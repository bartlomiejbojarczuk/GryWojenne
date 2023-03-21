#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QDialog>

namespace Ui {
class battlewindow;
}

class battlewindow : public QDialog
{
    Q_OBJECT

public:
    explicit battlewindow(QWidget *parent = nullptr);
    ~battlewindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::battlewindow *ui;
};

#endif // BATTLEWINDOW_H
