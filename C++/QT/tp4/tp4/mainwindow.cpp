#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->actionA_propos,SIGNAL(triggered()),this, SLOT(aPropos()));
    connect(ui->actionNouveau,SIGNAL(triggered()),this, SLOT(nouveau()));
    connect(ui->actionCopier, SIGNAL(triggered()), this, SLOT(copier()));
    connect(ui->actionCouper, SIGNAL(triggered()), this, SLOT(couper()));
    connect(ui->actionColler, SIGNAL(triggered()), this, SLOT(coller()));

    connect(ui->actionEnreg, SIGNAL(triggered()), this, SLOT(enregistrer()));
    connect(ui->actionEnregistrer_sous, SIGNAL(triggered()), this, SLOT(enregistrerSous()));
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(parcourir()));

    this->setWindowTitle("HTML Edit v1.0");

    stat = new Stat(this,ui->tabWidget);

    connect(ui->tabWidget,SIGNAL(currentChanged(int)), this, SLOT(changeWidget()));
    connect(QApplication::clipboard(),SIGNAL(dataChanged()),this,SLOT(changeClipBoard()));

    ui->statusBar->addPermanentWidget(stat);

    ui->tab->setStat(stat);
    ui->tab_2->setStat(stat);

    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this , SLOT(tabClose(int)));

    connect(static_cast<DocWidget*>(ui->tabWidget->currentWidget()), SIGNAL(contentsChange()), this, SLOT(OnOffActions()));

    OnOffActions();
    changeClipBoard();
    ui->tabWidget->setTabText(0,"Nouveau");
    ui->tabWidget->setTabText(1,"Nouveau");





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeWidget(){
    stat->changeSrc();
    OnOffActions();
    connect(static_cast<DocWidget*>(ui->tabWidget->currentWidget()), SIGNAL(contentsChange()), this, SLOT(OnOffActions()));
}

void MainWindow::changeClipBoard(){
    QClipboard* clip = QApplication::clipboard();
    if(clip->text().isEmpty() )
    {
        ui->actionColler->setEnabled(false);
    }
    else
    {
        ui->actionColler->setEnabled(true);
    }
}

void MainWindow::aPropos(){
    QMessageBox box(this);
    box.setWindowTitle("A propos de HTMLEdit v1.0");
    box.setText("HTMLEdit v1.0\n(c) 2015 Quentin DERORY");
    box.exec();
}

void MainWindow::nouveau(){
    ui->tabWidget->addTab(new DocWidget(this,stat) ,"Nouveau");
}

void MainWindow::copier(){
    QWidget* current = ui->tabWidget->currentWidget();
    DocWidget* curr = static_cast<DocWidget*>(current);
    QTextEdit* src = curr->getSrc();
    src->copy();

}

void MainWindow::couper(){
    QWidget* current = ui->tabWidget->currentWidget();
    DocWidget* curr = static_cast<DocWidget*>(current);
    QTextEdit* src = curr->getSrc();
    src->cut();

}
void MainWindow::coller(){
    QWidget* current = ui->tabWidget->currentWidget();
    DocWidget* curr = static_cast<DocWidget*>(current);
    QTextEdit* src = curr->getSrc();
    src->paste();

}

void MainWindow::enregistrer(){


    QWidget* current = ui->tabWidget->currentWidget();
    DocWidget* curr = static_cast<DocWidget*>(current);
    QTextEdit* src = curr->getSrc();
 if (curr->getFile() == 0)
    {
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer", QString(), "Tout");

    if(fichier != 0)
    {

      //Enregistrement
          curr->setFile(fichier);
          QFile* sauvegarde = curr->getFile();
          if (sauvegarde->open(QFile::WriteOnly))
          {
              QTextStream out(sauvegarde);
              out << src->toPlainText();
              sauvegarde->close();
              curr->setContentsChanged(false);
              ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),fichier);

          }
    }
    }
    else
    {
        QFile* sauvegarde = curr->getFile();
        if (sauvegarde->open(QFile::WriteOnly))
        {
            QTextStream out(sauvegarde);
            out << src->toPlainText();
            sauvegarde->close();
            curr->setContentsChanged(false);
        }
    }

}


void MainWindow::enregistrerSous(){
    QWidget* current = ui->tabWidget->currentWidget();
    DocWidget* curr = static_cast<DocWidget*>(current);
    QTextEdit* src = curr->getSrc();

    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer", QString(), "Tout");

    if(fichier != 0)
    {

      //Enregistrement
        curr->setFile(fichier);
        QFile* sauvegarde = curr->getFile();
          if (sauvegarde->open(QFile::WriteOnly))
          {
              QTextStream out(sauvegarde);
              out << src->toPlainText();
              sauvegarde->close();
              curr->setContentsChanged(false);
              ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),fichier);
          }
    }

}

void MainWindow::parcourir(){
    //On ouvre une boîte de dialogue
     QString chemin = QFileDialog::getOpenFileName(this, "Ouvrir","lol");

     if(chemin!=0)
     {

         //On ajoute un nouvel onglet et on se place sur celui ci
         DocWidget* nouveau = new DocWidget(this,stat);
         ui->tabWidget->addTab(nouveau,chemin);
         ui->tabWidget->setCurrentWidget(nouveau);

        //On récupère le texte du fichier
         nouveau->setFile(chemin);
         QFile* file = nouveau->getFile();
         if (file->open(QFile::ReadOnly))
         {
            QTextStream out(file);
            nouveau->getSrc()->setPlainText(out.readAll());
         }
     }

}

void MainWindow::tabClose(int i){
    DocWidget* widget = static_cast<DocWidget*> (ui->tabWidget->widget(i));
    if(widget->getContentsChanged())
    {
        int reponse = QMessageBox::question(this, "Fermeture", "Souhaitez-vous fermer là fenetre", QMessageBox::Yes | QMessageBox::No);

           if (reponse == QMessageBox::Yes)
           {
               ui->tabWidget->removeTab(i);
           }
           else if (reponse == QMessageBox::No)
           {
            //Rien faire
           }
    }
    else
    {
        ui->tabWidget->removeTab(i);
    }
}

void MainWindow::OnOffActions(){
    DocWidget* current = static_cast<DocWidget*> (ui->tabWidget->currentWidget());
    if(current->getContentsChanged())
    {
        ui->actionEnreg->setEnabled(true);
        ui->actionEnregistrer_sous->setEnabled(true);

    }
    else
    {
        ui->actionEnreg->setEnabled(false);
        ui->actionEnregistrer_sous->setEnabled(false);
    }

}
