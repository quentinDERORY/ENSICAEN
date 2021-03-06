#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vue.h>
#include <InvoiceModel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void cell(int,int);

    void on_actionQuitter_triggered();

    void on_actionOuvrir_triggered();

private:
    Ui::MainWindow *ui;
    InvoiceModel* model;
};

#endif // MAINWINDOW_H
