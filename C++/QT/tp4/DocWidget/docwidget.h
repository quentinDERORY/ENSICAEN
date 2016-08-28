#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QWidget>

namespace Ui {
class DocWidget;
}

class DocWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DocWidget(QWidget *parent = 0);
    ~DocWidget();

private:
    Ui::DocWidget *ui;
};

#endif // DOCWIDGET_H
