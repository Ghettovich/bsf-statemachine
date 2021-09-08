#ifndef BSF_STATEMACHINE__MAINWINDOW_H_
#define BSF_STATEMACHINE__MAINWINDOW_H_

#include <QMainWindow>
#include <QToolBar>
#include <QStatusBar>

#include "PavementMachine.h"


namespace Ui {
class MainWindow;
}


class QAction;
class QMenu;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  virtual ~MainWindow();

 public slots:
  void onClickStartPreparingRecipe();

 private:
  Ui::MainWindow *ui;
  PavementMachine machine;
};

#endif //BSF_STATEMACHINE__MAINWINDOW_H_
