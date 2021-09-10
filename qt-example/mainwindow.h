#ifndef BSF_STATEMACHINE__MAINWINDOW_H_
#define BSF_STATEMACHINE__MAINWINDOW_H_

#include <QMainWindow>
#include <QToolBar>
#include <QStatusBar>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QAbstractTransition>

#include "state/LiftIdleState.h"

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
  void onStartedStatemachine();
  void onEnteredS2();
  void onFinishedStateMachine();
  void onEnteredS13();

 private:
  Ui::MainWindow *ui;

  QStateMachine *qmachine = new QStateMachine;
};

#endif //BSF_STATEMACHINE__MAINWINDOW_H_
