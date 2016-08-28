#include "vue.h"

Vue::Vue(QWidget *parent) :
    QWidget(parent)
{

}

void Vue::setModel(InvoiceModel *source){
    modele = source;
    connect(modele,SIGNAL(notify()),this,SLOT(update()));
}




void Vue::paintEvent(QPaintEvent* e){
    QPainter painter(this);

    painter.setBackground(QBrush(QColor(Qt::white)));


    //Coordonnée client
    QRectF rectangle(10.0, 20.0, 180.0, 80.0);
    painter.drawRoundedRect(rectangle, 20.0, 15.0);
    QString rect = " " + modele->firstname() + "   " + modele->lastname() + "\n " + modele->addressLine1() +"\n " + modele->addressLine2() +"\n " + modele->zipcode() + "  " + modele->city();
    painter.drawText(rectangle,rect);

    //Tableau

    QRectF table_header_0(10,150,140,20);
    painter.drawRect(table_header_0);
    painter.drawText(table_header_0," Item");
    QRectF table_cell_0(10,170,140,300);
    painter.drawRect(table_cell_0);

    QRectF table_header_1(150,150,80,20);
    painter.drawRect(table_header_1);
    painter.drawText(table_header_1," Quantity");
    QRectF table_cell_1(150,170,80,300);
    painter.drawRect(table_cell_1);


    QRectF table_header_2(230,150,80,20);
    painter.drawRect(table_header_2);
    painter.drawText(table_header_2," Unit price");
    QRectF table_cell_2(230,170,80,300);
    painter.drawRect(table_cell_2);


    QRectF table_header_3(310,150,80,20);
    painter.drawRect(table_header_3);
    painter.drawText(table_header_3," Price");
    QRectF table_cell_3(310,170,80,300);
    painter.drawRect(table_cell_3);



    //Remplissage du tableau
     QString cell_0 = "" ;
     QString cell_1 = "";
     QString cell_2 = "";
     QString cell_3 = "";
    for(int i=0;i<14;i++){
    cell_0 += modele->cell(i,1) +"\n";
    cell_1 += modele->cell(i,2) +"\n";
    cell_2 += modele->cell(i,3) +"\n";
    cell_3 += modele->cell(i,4) +"\n";


    }

    painter.drawText(table_cell_0,cell_0);
    painter.drawText(table_cell_1,cell_1);
    painter.drawText(table_cell_2,cell_2);
    painter.drawText(table_cell_3,cell_3);

    //debug
    /*
    QRectF table(10,480,200,200);
    painter.drawRect(table);
    painter.drawText(table,modele->cell(0,0)+"\n"+ modele->cell(0,1));
*/
}
