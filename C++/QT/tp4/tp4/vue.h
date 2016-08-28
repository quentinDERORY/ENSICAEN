#ifndef VUE_H
#define VUE_H

#include <QTextEdit>

class Vue : public QTextEdit
{
    Q_OBJECT
public:
    explicit Vue(QWidget *parent = 0,QTextDocument* source = 0);
    void update();
    void setDocument();

signals:

public slots:

private:
    QTextDocument* src;


};

#endif // VUE_H
