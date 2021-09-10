#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "StringTransition.h"
#include "LiftTransition.h"


#include <QDebug>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QObject::connect(ui->pushButton, &QPushButton::clicked,
                   this , &MainWindow::onClickStartPreparingRecipe);

  //QStateMachine machine;
  QState *s1 = new QState();
  QState *s11 = new QState(s1);
  QState *s12 = new QState(s1);
  QState *s13 = new QState(s1);
  QFinalState *s2 = new QFinalState();

  s1->setInitialState(s11);
  qmachine->addState(s1);

  StringTransition *t1 = new StringTransition("Hello");
  t1->setTargetState(s12);
  s11->addTransition(t1);

  StringTransition *t2 = new StringTransition("world");
  t2->setTargetState(s13);
  s12->addTransition(t2);

  LiftTransition *t3 = new LiftTransition(false, true, false);
  t3->setTargetState(s2);
  s13->addTransition(t3);

  qmachine->addState(s2);
  qmachine->setInitialState(s1);

  QObject::connect(s2, &QState::entered, this, &MainWindow::onEnteredS2);
  QObject::connect(qmachine, &QStateMachine::started, this, &MainWindow::onStartedStatemachine);
  QObject::connect(qmachine, &QStateMachine::finished, this, &MainWindow::onFinishedStateMachine);
  QObject::connect(s13, &QState::entered, this, &MainWindow::onEnteredS13);

}

MainWindow::~MainWindow() {

}
void MainWindow::onClickStartPreparingRecipe() {
  if(!qmachine->isRunning()) {
    qmachine->start();
  }
}


void MainWindow::onEnteredS2() {
  qDebug() << "Entered S2";
}

void MainWindow::onFinishedStateMachine() {
  qDebug() << "Finished statemachine";
  qmachine->stop();
}

void MainWindow::onStartedStatemachine() {
  qmachine->postEvent(new StringEvent("Hello"));
  qmachine->postEvent(new LiftEvent(false, false, false));
  qmachine->postEvent(new StringEvent("world"));
}

void MainWindow::onEnteredS13() {
  qmachine->postEvent(new LiftEvent(true, false, false));
  qmachine->postEvent(new LiftEvent(false, true, false));
}
