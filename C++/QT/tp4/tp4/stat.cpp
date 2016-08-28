#include "stat.h"

Stat::Stat(QWidget *parent,QTabWidget* tab) :
    QLabel(parent)
{
    this->tab = tab;
    src =static_cast<DocWidget*> ( tab->currentWidget() );
}


void Stat::update(){
    QTextEdit* text = src->getSrc();
    int line_count = 0;
    QString plainText = text->toPlainText();
    for(int i = 0; i <plainText.length();i++)
    {
        if(plainText.at(i) == QChar('\n'))
            line_count++;
    }


    QString res = QString("Caractères : " + QString::number(plainText.length()-line_count) + " Lignes : "+ QString::number(line_count) );
    this->setText(res);

}

void Stat::changeSrc(){
     src =static_cast<DocWidget*> ( tab->currentWidget() );
     update();
}

