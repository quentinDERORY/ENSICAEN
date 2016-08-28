#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSlider>
#include <QLCDNumber>
#include <QString>
#include <QPalette>
#include <QColor>
#include <QColorDialog>
#include <QFont>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget();

public slots:
    void reecrire(const QString &);
    void changerCouleur(const QString &);
    void colorDialog();
    void changeSize(const int &);
    void alert_erreur();
private:
    QLineEdit *saisie;
    QLineEdit *saisieLectSeule;
    QComboBox *liste;
    QSlider *curseur;
    QLCDNumber *affichageNum;
    QColor color;
    QRegExpValidator sv;

};

#endif // MAINWIDGET_H
