#include "LiftArrived.h"

#include <QDebug>

LiftArrived::LiftArrived(bool proximityLoad, bool proximityDrop, bool relayLiftOn) :
    m_relayOn(relayLiftOn),
    m_proximityLoad(proximityLoad),
    m_proximityDrop(proximityDrop) {
}

bool LiftArrived::eventTest(QEvent *e) {
  qDebug() << "Lift arrived eventTest";

  return (m_relayOn && (m_proximityLoad || m_proximityDrop));

//  if (e->type() != QEvent::Type(QEvent::User + 1)) { // LiftEvent
//    return false;
//  }
//
//  auto *se = dynamic_cast<LiftEvent *>(e);
//  return (!m_proximityLoad && m_proximityDrop && !m_relayOn);
}

void LiftArrived::onTransition(QEvent *) {
  qDebug() << "on transition...";
}
