#ifndef STAT_H
#define STAT_H

#include <QLabel>
#include <QTextEdit>
#include <QTabWidget>

class Stat;

#include <docwidget.h>

class Stat : public QLabel
{
    Q_OBJECT
public:
    explicit Stat(QWidget *parent = 0,QTabWidget* tab = 0);
    void update();
    void setDocument();

signals:

public slots:
    void changeSrc();

private:
    QTabWidget* tab;
    DocWidget* src;

};

#endif // STAT_H
