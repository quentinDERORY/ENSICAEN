#include "docwidget.h"
#include "ui_docwidget.h"

DocWidget::DocWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocWidget)
{
    ui->setupUi(this);
}

DocWidget::~DocWidget()
{
    delete ui;
}
