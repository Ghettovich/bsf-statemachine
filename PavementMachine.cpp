#include "PavementMachine.h"
#include "statemachine/LiftEvent.h"
#include "statemachine/events/LiftIdle.h"
#include "statemachine/events/LiftMoving.h"
#include "statemachine/events/LiftArrived.h"
#include "statemachine/events/LiftEventData.h"

#include <QState>
#include <QFinalState>

PavementMachine::PavementMachine() {
  auto *s1 = new QState(); // Initial state
  auto *s11 = new QState(s1); // Lift is idle. Relay is OFF, proximity drop is ON, load is OFF --> toggleRelay
  auto *s12 = new QState(s1); // Lift is moving. Relay is ON, both proximities are OFF --> wait for proximity
  auto *s13 = new QState(s1); // Lift is moving. Relay is ON but proximity load is ON and drop is OFF --> toggleRelay
  auto *s2 = new QFinalState(); // Lift stopped moving. Relay is OFF. Proximity load is ON and proximity drop OFF

  s1->setInitialState(s11);
  machine.addState(s1);

  auto *t1 = new LiftIdle(false, true, false);
  t1->setTargetState(s12);
  s11->addTransition(t1);

  auto *t2 = new LiftMoving(false, false, true);
  t2->setTargetState(s13);
  s12->addTransition(t2);

  auto *t3 = new LiftArrived(true, false, true);
  t3->setTargetState(s2);
  s13->addTransition(t3);

  machine.addState(s2);
  machine.setInitialState(s1);

  machine.start();

  QObject::connect(s12, &QState::entered, [=]() {
    qDebug() << "s12 entered, toggle lift relay";
  });

  QObject::connect(s13, &QState::entered, [=]() {
    qDebug() << "s13 entered, lift is moving";
  });

  QObject::connect(&machine, &QStateMachine::finished, [=]() {
    qDebug() << "please do";
  });


  machine.postEvent(new LiftEvent(false, true, false));
  machine.postEvent(new LiftEvent(false, false, true));
  machine.postEvent(new LiftEvent(true, false, true));
}

void PavementMachine::sendLiftToLoad() {

}

