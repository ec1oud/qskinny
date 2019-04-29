#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QskWindow.h>

class MainWindow : public QskWindow
{
  public:
    MainWindow();

  private:
    QQuickItem* headerBar() const;
    QQuickItem* mainContent() const;
    QQuickItem* footerBar() const;
};

#endif
