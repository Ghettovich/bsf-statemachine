#include "LiftIdle.h"
#include "LiftEventData.h"

#include <QDebug>

LiftIdle::LiftIdle(bool proximityLoad, bool proximityDrop, bool relayLiftOn) :
    m_relayOn(relayLiftOn),
    m_proximityLoad(proximityLoad),
    m_proximityDrop(proximityDrop) {
}

bool LiftIdle::eventTest(QEvent *e) {
  qDebug() << "Lift Idle eventTest";

//  if (e->type() != QEvent::Type(QEvent::User + 1)) { // LiftEvent
//    return false;
//  }
//
//  auto *se = dynamic_cast<LiftEvent *>(e);
  return (!m_proximityLoad && m_proximityDrop && !m_relayOn);
}

void LiftIdle::onTransition(QEvent *) {
  qDebug() << "on transition...";
}