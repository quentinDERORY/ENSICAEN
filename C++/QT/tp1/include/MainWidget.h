/**
 * @file   MainWidget.h
 * @author Sebastien Fourey
 * 
 * @brief  Class of the application's main Widget .
 */

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <iostream>
#include "ColorWidget.h"
#include <QTimer>
#include <QTimeEdit>

/**
 * Class of the application's main Widget .
 */
class MainWidget : public QWidget {

  Q_OBJECT     // Tell "moc" that this is a signal sender or receiver.

public:

  /** 
   * Default constructor.
   */
  MainWidget();
 
public slots:

  /** 
   * Answer to the "Quit" push button activation.
   */
  void quitPressed();

  /** 
   * Answer to a change of color in the ColorWidget.
   * 
   * @param r The red component in [0..255].
   * @param g The green component in [0..255].
   * @param b The blue component in [0..255].
   */ 
  void colorChanged(int r, int g, int b);

  void updateTime();

private:

  QLineEdit   *lineDisplay;	/**< A text field */
  QLineEdit   *lineDisplay2;
  QTimeEdit   *time_display;
  QTimer      *timer;
protected:
    void mouseMoveEvent(QMouseEvent * e);
};

#endif
