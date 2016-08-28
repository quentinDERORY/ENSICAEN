#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QButtonGroup>
#include <Controller.h>
#include <QDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
     void aPropos();
     void setBase(const QString &);
     void command(const int &);
     void suffixe(const bool &);
     //void clavier(QString );

private:
     void setBaseDec();
     void setBaseHex();
     void setBaseBin();
     void initController();
     void affiche();
    // Controller::ButtonID charToID(QChar c);


    Ui::MainWindow *ui;
    QButtonGroup* buttGrp;
    Controller* controller;
    bool suff;

};

#endif // MAINWINDOW_H
