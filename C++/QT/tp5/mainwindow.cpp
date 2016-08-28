#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    model = new InvoiceModel();
    ui->setupUi(this);
    ui->vue->setModel(model);

    //Connect
    connect(ui->first_name,SIGNAL(textEdited(QString)),model,SLOT(setFirstname(QString)));
    connect(ui->last_name,SIGNAL(textEdited(QString)),model,SLOT(setLastname(QString)));
    connect(ui->adress1,SIGNAL(textEdited(QString)),model,SLOT(setAddressLine1(QString)));
    connect(ui->adress2,SIGNAL(textEdited(QString)),model,SLOT(setAddressLine2(QString)));
    connect(ui->city,SIGNAL(textEdited(QString)),model,SLOT(setCity(QString)));
    connect(ui->zipCode,SIGNAL(textEdited(QString)),model,SLOT(setZipcode(QString)));

    connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(cell(int,int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cell(int x, int y){

    QString tmp = ui->tableWidget->itemAt(x,y)->text();

    model->setCell(x,y,tmp);
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::on_actionOuvrir_triggered()
{
    model = new InvoiceModel();
    ui->vue->setModel(model);
    ui->adress1->clear();
    ui->adress2->clear();
    ui->first_name->clear();
    ui->last_name->clear();
    ui->city->clear();
    ui->zipCode->clear();
    ui->tableWidget->clear();

}
