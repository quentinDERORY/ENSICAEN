#include "docwidget.h"

DocWidget::DocWidget(QWidget *parent,Stat* stat) :
    QSplitter(parent)
{
    vBoxLayout = new QVBoxLayout();
    left = new QTextEdit();
    vue = new Vue(0,left->document());
    vue->setReadOnly(true);
    label = new QLabel();
    label->setText("Aperçu");
    right = new QWidget();

    right->setLayout(vBoxLayout);
    vBoxLayout->addWidget(label);
    vBoxLayout->addWidget(vue);
    this->addWidget(left);
    this->addWidget(right);
    this->show();

   sauvegarde = 0;

   this->stat = stat;




    connect(left->document(),SIGNAL(contentsChanged()),this,SLOT(notify()));
    contentsChanged = false;


}


void DocWidget::notify(){
    vue->update();
    stat->update();
    contentsChanged=true;
    emit contentsChange();
}

QTextEdit* DocWidget::getSrc(){
    return left;
}

void DocWidget::setFile(QString file){
    sauvegarde = new QFile(file);
}

QFile* DocWidget::getFile(){
    return sauvegarde;
}

void DocWidget::setStat(Stat *stat){
    this->stat = stat;
}

void DocWidget::setContentsChanged(bool val){
    contentsChanged = val;
    emit contentsChange();
}

bool DocWidget::getContentsChanged(){
    return contentsChanged;
}


