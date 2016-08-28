/**
 * @file   MainWidget.cpp
 // * @author Quentin Derory
 *
 * @brief  MainWidget methods definitions.
 */
#include "MainWidget.h"
#include <QMouseEvent>
#include <QString>
#include <QMessageBox>
#include <QTimeEdit>
#include <QTimer>
using namespace std;

MainWidget::MainWidget()
{
  setGeometry(100,100,300,500);

  setMouseTracking(true);


  QLabel *label = new QLabel("Colors, signals, and slots",this);
  label->setGeometry(10,10,290,30);
  label->setFont(QFont("Arial",14,QFont::Bold));

  lineDisplay2 = new QLineEdit("",this);
  lineDisplay2->setGeometry(50,70,200,30);
  lineDisplay2->setAlignment(Qt::AlignHCenter);
  lineDisplay2->setReadOnly(true);



  lineDisplay = new QLineEdit("",this);
  lineDisplay->setGeometry(50,110,200,30);
  lineDisplay->setAlignment(Qt::AlignHCenter);
  lineDisplay->setReadOnly(true);//On le met en read-only

  time_display = new QTimeEdit(QTime::currentTime(), this);
  time_display->setGeometry(100,400,100,100);
  time_display->setAlignment(Qt::AlignHCenter);

  ColorWidget *colorWidget = new ColorWidget(this);
  colorWidget->setGeometry(100,200,80,30);

  QPushButton *pushButtonRandomColor = new QPushButton("Random color",this);
  pushButtonRandomColor->setGeometry(60,240,160,30);

  QPushButton *pushButtonQuit = new QPushButton("Quit",this);
  pushButtonQuit->setGeometry(100,250,80,30);

  timer = new QTimer(this);
  timer->start(1000);

  connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));


  connect(pushButtonQuit,SIGNAL(clicked()),
          this,SLOT(quitPressed()));

  connect(pushButtonRandomColor,SIGNAL(clicked()),
          colorWidget,SLOT(changeColor()));

  connect(colorWidget,SIGNAL(colorChanged(int,int,int)),
          this,SLOT(colorChanged(int,int,int)));
}

void MainWidget::quitPressed()
{
  QMessageBox::StandardButton button;
  button = QMessageBox::question(this,
                                 "You want to quit...",
                                 "Are you sure that you want to quit"
                                 " this great application?",
                                 QMessageBox::Yes|QMessageBox::No,
                                 QMessageBox::No );
  if ( button == QMessageBox::Yes ) {
    close();
  }
}


void MainWidget::updateTime(){
        time_display->setTime(QTime::currentTime());
}

void MainWidget::colorChanged(int r, int g, int b)
{
  QString text("Color: R(%1) G(%2) B(%3)");
  lineDisplay->setText(text.arg(r).arg(g).arg(b));
}

void MainWidget::mouseMoveEvent(QMouseEvent * e){
    QString text("(%1,%2)");
      lineDisplay2->setText(text.arg(e->x()).arg(e->y()));

      if(e->buttons() == Qt::LeftButton)
        lineDisplay2->setAlignment(Qt::AlignLeft);
      else if(e->buttons() == Qt::RightButton)
        lineDisplay2->setAlignment(Qt::AlignRight);
      else if(e->buttons() == Qt::MiddleButton)
        lineDisplay2->setAlignment(Qt::AlignHCenter);
}
