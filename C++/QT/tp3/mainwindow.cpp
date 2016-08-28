#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->actionA_propos,SIGNAL(triggered()), this, SLOT(aPropos()));
    ui->lineEdit->setReadOnly(true);

    buttGrp = new QButtonGroup(this);
    buttGrp->addButton(ui->cButton,Controller::Button_Clear);
    buttGrp->addButton(ui->button_0,Controller::Button_0);
    buttGrp->addButton(ui->button_1,Controller::Button_1);
    buttGrp->addButton(ui->button_2,Controller::Button_2);
    buttGrp->addButton(ui->button_3,Controller::Button_3);
    buttGrp->addButton(ui->button_4,Controller::Button_4);
    buttGrp->addButton(ui->button_5,Controller::Button_5);
    buttGrp->addButton(ui->button_6,Controller::Button_6);
    buttGrp->addButton(ui->button_7,Controller::Button_7);
    buttGrp->addButton(ui->button_8,Controller::Button_8);
    buttGrp->addButton(ui->button_9,Controller::Button_9);
    buttGrp->addButton(ui->button_A,Controller::Button_A);
    buttGrp->addButton(ui->button_B,Controller::Button_B);
    buttGrp->addButton(ui->button_C,Controller::Button_C);
    buttGrp->addButton(ui->button_D,Controller::Button_D);
    buttGrp->addButton(ui->button_E,Controller::Button_E);
    buttGrp->addButton(ui->button_F,Controller::Button_F);
    buttGrp->addButton(ui->button_plus,Controller::Button_Plus);
    buttGrp->addButton(ui->button_minus,Controller::Button_Minus);
    buttGrp->addButton(ui->button_mtp,Controller::Button_Multiply);
    buttGrp->addButton(ui->button_div,Controller::Button_Divide);
    buttGrp->addButton(ui->button_equal,Controller::Button_Equal);
    buttGrp->addButton(ui->button_dot,Controller::Button_Dot);

    initController();
    suff=false;
    connect(ui->actionSuffixe,SIGNAL(toggled(const bool &)),this,SLOT(suffixe(const bool &)));

    ui->widget->installEventFilter(this);
}
bool MainWindow::eventFilter(QObject *target, QEvent *event)
{

        if (event->type() == QEvent::KeyPress) {

            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Equal) {
                if(controller->command(Controller::Button_Equal))
                    affiche();
                return true;
                }
            else if(keyEvent->key() == Qt::Key_0){
                if(controller->command(Controller::Button_0))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_1){
                if(controller->command(Controller::Button_1))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_2){
                if(controller->command(Controller::Button_2))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_3){
                if(controller->command(Controller::Button_3))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_4){
                if(controller->command(Controller::Button_4))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_5){
                if(controller->command(Controller::Button_5))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_6){
                if(controller->command(Controller::Button_6))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_7){
                if(controller->command(Controller::Button_7))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_8){
                if(controller->command(Controller::Button_8))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_9){
                if(controller->command(Controller::Button_9))
                    affiche();
                return true;
            }

            else if(keyEvent->key() == Qt::Key_Plus){
                if(controller->command(Controller::Button_Plus))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_Minus){
                if(controller->command(Controller::Button_Minus))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_Slash){
                if(controller->command(Controller::Button_Divide))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_multiply){
                if(controller->command(Controller::Button_Multiply))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_A){
                if(controller->command(Controller::Button_A))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_B){
                if(controller->command(Controller::Button_B))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_C){
                if(controller->command(Controller::Button_C))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_D){
                if(controller->command(Controller::Button_D))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_E){
                if(controller->command(Controller::Button_E))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_F){
                if(controller->command(Controller::Button_F))
                    affiche();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_Comma){
                if(controller->command(Controller::Button_Dot))
                    affiche();
                return true;
            }


            }



        return false;
}

void MainWindow::initController() {
    controller = new Controller();
    setBaseDec();
    ui->comboBox->setCurrentIndex(0);
    connect(ui->comboBox,SIGNAL(activated(const QString &) ), this, SLOT(setBase(const QString &)));
    connect(buttGrp,SIGNAL(buttonClicked(const int & )), this, SLOT(command(const int &)));
}

void MainWindow::aPropos(){
    QMessageBox box(this);
    box.setWindowTitle("A propos de Calculatrice");
    box.setText("Calculatrice\n(c) 2015 Quentin DERORY");
    box.exec();
}

void MainWindow::setBaseDec(){
    ui->button_A->setEnabled(false);
    ui->button_B->setEnabled(false);
    ui->button_C->setEnabled(false);
    ui->button_D->setEnabled(false);
    ui->button_E->setEnabled(false);
    ui->button_F->setEnabled(false);

    ui->button_2->setEnabled(true);
    ui->button_3->setEnabled(true);
    ui->button_4->setEnabled(true);
    ui->button_5->setEnabled(true);
    ui->button_6->setEnabled(true);
    ui->button_7->setEnabled(true);
    ui->button_8->setEnabled(true);
    ui->button_9->setEnabled(true);
    ui->button_dot->setEnabled(true);

    affiche();
}
void MainWindow::setBaseHex(){
    ui->button_A->setEnabled(true);
    ui->button_B->setEnabled(true);
    ui->button_C->setEnabled(true);
    ui->button_D->setEnabled(true);
    ui->button_E->setEnabled(true);
    ui->button_F->setEnabled(true);

    ui->button_2->setEnabled(true);
    ui->button_3->setEnabled(true);
    ui->button_4->setEnabled(true);
    ui->button_5->setEnabled(true);
    ui->button_6->setEnabled(true);
    ui->button_7->setEnabled(true);
    ui->button_8->setEnabled(true);
    ui->button_9->setEnabled(true);
    ui->button_dot->setEnabled(false);

    affiche();
}

void MainWindow::setBaseBin(){
    ui->button_A->setEnabled(false);
    ui->button_B->setEnabled(false);
    ui->button_C->setEnabled(false);
    ui->button_D->setEnabled(false);
    ui->button_E->setEnabled(false);
    ui->button_F->setEnabled(false);


    ui->button_2->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_4->setEnabled(false);
    ui->button_5->setEnabled(false);
    ui->button_6->setEnabled(false);
    ui->button_7->setEnabled(false);
    ui->button_8->setEnabled(false);
    ui->button_9->setEnabled(false);
    ui->button_dot->setEnabled(false);

    affiche();
}

void MainWindow::setBase(const QString & selected){
    if(selected == "Dec"){
        controller->setBase(Controller::Dec);
        setBaseDec();
    }else if(selected == "Hex"){
        controller->setBase(Controller::Hex);
        setBaseHex();
    }else if(selected == "Bin"){
        controller->setBase(Controller::Bin);
        setBaseBin();
    }

}

void MainWindow::command(const int & i){
    Controller::ButtonID val = static_cast<Controller::ButtonID>(i);
    if(controller->command(val))
    {

        affiche();
    }
}

void MainWindow::suffixe(const bool & tmp){
    suff=tmp;
    affiche();
}

void MainWindow::affiche(){
    if(suff)
    {
        if(ui->comboBox->currentText().startsWith("B"))
        {
            ui->lineEdit->setText(controller->getText() + "b");
        }
        else if(ui->comboBox->currentText().startsWith('H'))
        {
            ui->lineEdit->setText(controller->getText() + "Ch");
        }
        else {
             ui->lineEdit->setText(controller->getText());
        }
    }
    else{
        ui->lineEdit->setText(controller->getText() );
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
