#ifndef VUE_H
#define VUE_H

#include <QWidget>
#include <InvoiceModel.h>
#include <QPainter>
#include <QRectF>
#include <QImage>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>

class Vue : public QWidget
{
    Q_OBJECT
public:
    explicit Vue(QWidget *parent = 0);
    void paintEvent(QPaintEvent* e);
    void setModel(InvoiceModel* source);


signals:

public slots:

private:
    InvoiceModel* modele;

};

#endif // VUE_H
