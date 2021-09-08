#include "LiftMoving.h"

#include <QDebug>

LiftMoving::LiftMoving(bool proximityLoad, bool proximityDrop, bool relayLiftOn) :
    m_relayOn(relayLiftOn),
    m_proximityLoad(proximityLoad),
    m_proximityDrop(proximityDrop) {
}

bool LiftMoving::eventTest(QEvent *e) {
  qDebug() << "Lift moving eventTest";

  return (!m_proximityLoad && !m_proximityDrop && m_relayOn);

//  if (e->type() != QEvent::Type(QEvent::User + 1)) { // LiftEvent
//    return false;
//  }
//
//  auto *se = dynamic_cast<LiftEvent *>(e);
//  return (!m_proximityLoad && m_proximityDrop && !m_relayOn);
}

void LiftMoving::onTransition(QEvent *) {
  qDebug() << "on transition...";
}
