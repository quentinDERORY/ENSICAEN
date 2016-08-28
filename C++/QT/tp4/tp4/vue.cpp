#include "vue.h"

Vue::Vue(QWidget *parent,QTextDocument* source) :
    QTextEdit(parent)
{
    src = source;
}

void Vue::update(){
    this->setHtml( src->toPlainText());
}
