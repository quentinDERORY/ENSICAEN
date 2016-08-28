#include "mainwidget.h"
#include "simplevalidator.h"
#include <QMessageBox>

MainWidget::MainWidget() {
    setGeometry(10,10,300,350);


    QLabel *label = new QLabel("Widgets, signaux, slots, couleurs, fontes", this);
    label->setGeometry(10,10,280,40);

    saisie = new QLineEdit("Texte_sans_espace", this);
    saisie->setGeometry(50,70,200,30);
    SimpleValidator* sv  = new SimpleValidator();
    saisie->setValidator(sv);

    saisieLectSeule = new QLineEdit("TEXTE_SANS_ESPACE",this);
    saisieLectSeule->setGeometry(50,110,200,30);
    saisieLectSeule->setReadOnly(true);

    QPushButton *boutonColor = new QPushButton("Select Color", this);
    boutonColor->setGeometry(70,150,160,30);

    liste = new QComboBox(this);
    liste->setGeometry(90,190,120,30);
    liste->addItem("Red");
    liste->addItem("Green");
    liste->addItem("Blue");
    liste->addItem("Cyan");
    liste->addItem("Magenta");
    liste->addItem("Yellow");
    liste->addItem("Grey");

    curseur = new QSlider(Qt::Horizontal, this);
    curseur->setGeometry(60,260,170,20);

    affichageNum = new QLCDNumber(this);
    affichageNum->setGeometry(230,245,40,40);
    affichageNum->display(12);

    QPushButton *boutonQuit = new QPushButton("Quit", this);
    boutonQuit->setGeometry(100,300,80,30);

    QColor color('Black');


    connect(boutonQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(saisie, SIGNAL(textChanged(const QString &)),
            this, SLOT(reecrire(const QString)));
    connect(liste,SIGNAL(activated(const QString &)),
            this,SLOT(changerCouleur(const QString &)));
    connect(boutonColor,SIGNAL(clicked()),
             this,SLOT(colorDialog()));
    connect(curseur,SIGNAL(valueChanged(const int &)),
            this,SLOT(changeSize(const int &)));
    connect(sv,SIGNAL(invalidInput()),
            this,SLOT(alert_erreur()));
}

void MainWidget::reecrire(const QString & texte) {
    saisieLectSeule->setText(texte.toUpper());
}

void MainWidget::changerCouleur(const QString & texte){
    QColor couleur(texte);
    if(color != couleur)
    {
        color=couleur;
        QPalette palette;
        palette.setColor(QPalette::Text,color);
        saisieLectSeule->setPalette(palette);
    }
}

void MainWidget::colorDialog(){
    QColorDialog w(this);
    QColor couleur = w.getColor();
    QPalette palette;
    palette.setColor(QPalette::Text,couleur);
    saisieLectSeule->setPalette(palette);
}

void MainWidget::changeSize(const int & tmp ){
    affichageNum->display(tmp);
    QFont font = saisieLectSeule->font();
    font.setPointSize(tmp);
    saisieLectSeule->setFont(font);
}

void MainWidget::alert_erreur(){
    QMessageBox::information(this, "titre", "erreur de saisie");

}
