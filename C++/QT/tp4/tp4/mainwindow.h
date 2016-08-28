#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QClipboard>
#include <docwidget.h>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <stat.h>
#include <QStatusBar>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QClipboard>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void aPropos();
    void nouveau();
    void copier();
    void coller();
    void couper();
    void enregistrer();
    void enregistrerSous();
    void parcourir();
    void tabClose(int);
    void changeWidget();
    void changeClipBoard();
    void OnOffActions();


private slots:

private:
    Ui::MainWindow *ui;
    Stat* stat;

};

#endif // MAINWINDOW_H
