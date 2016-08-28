#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>
#include <vue.h>
#include <QLabel>
#include <QString>
#include <QFile>

class DocWidget ;

#include <stat.h>

class DocWidget : public QSplitter
{
    Q_OBJECT
public:
    explicit DocWidget(QWidget *parent = 0,Stat* stat = 0);
    void addView(QString path);
    QTextEdit* getSrc();
    void setFile(QString file);
    QFile* getFile();
    void setStat(Stat* stat);
    bool getContentsChanged();
    void setContentsChanged(bool val);



signals:
    void contentsChange();

public slots:
    void notify();

private:
    QVBoxLayout* vBoxLayout;
    QTextEdit* left;
    QWidget* right;
    Vue* vue;
    QLabel* label;
    QFile* sauvegarde;
    Stat* stat;
    bool contentsChanged;


};

#endif // DOCWIDGET_H
