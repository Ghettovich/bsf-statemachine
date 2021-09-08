#include "LiftEvent.h"

#include "events/LiftEventData.h"

LiftTransition::LiftTransition(bool proximityLoad, bool proximityDrop, bool relayLiftOn) :
    m_relayOn(relayLiftOn),
    m_proximityLoad(proximityLoad),
    m_proximityDrop(proximityDrop) {
}

bool LiftTransition::eventTest(QEvent *e) {
  qDebug() << "eventTest Lift Transition";

  if (e->type() != QEvent::Type(QEvent::User + 1)) { // LiftEvent
    return false;
  }

  auto *se = dynamic_cast<LiftEvent *>(e);
  return (!m_proximityLoad && m_proximityDrop && !m_relayOn);
}

void LiftTransition::onTransition(QEvent *) {
  qDebug() << "on transition...";
}