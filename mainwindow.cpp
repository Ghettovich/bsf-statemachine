#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPushButton>
#include <QFinalState>


MainWindow::MainWindow(QWidget *parent)
    :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QObject::connect(ui->pushButton, &QPushButton::clicked,
                   this , &MainWindow::onClickStartPreparingRecipe);
}

MainWindow::~MainWindow() {

}
void MainWindow::onClickStartPreparingRecipe() {
  machine.sendLiftToLoad();
//  QState *s1 = new QState();
//  QState *s11 = new QState(s1);
//  QState *s12 = new QState(s1);
//  QState *s13 = new QState(s1);
//  s1->setInitialState(s11);
//  machine.addState(s1);
//  QFinalState *s2 = new QFinalState();
//  s1->addTransition(ui->pushButton, &QPushButton::clicked, s2);
//  machine.addState(s2);
//  machine.setInitialState(s1);
//
//  machine.start();
//
//  QObject::connect(s2, &QState::entered, [=](){
//    qDebug() << "on entered s2";
//  });
//
//  QObject::connect(&machine, &QStateMachine::finished, [=](){
//    qDebug() << "please do";
//  });
//
//  QObject::connect(ui->pushButton, &QPushButton::clicked, [=](){
//    qDebug() << "...";
//  });
}
