#include "LiftEvent.h"

LiftIdle::LiftIdle(bool proximity_load, bool proximity_drop, bool relay_lift_on) :
    LiftTransition(
        proximity_load,
        proximity_drop,
        relay_lift_on) {
}

bool LiftIdle::binLoadTestEvent() {
  return (!m_proximityLoad && m_proximityDrop && !m_relayOn);
}

LiftMoving::LiftMoving(bool proximity_load, bool proximity_drop, bool relay_lift_on)
    : LiftTransition(proximity_load,
                     proximity_drop,
                     relay_lift_on) {
}

bool LiftMoving::binLoadTestEvent() {
  return (!m_proximityLoad && !m_proximityDrop && m_relayOn);
}

LiftArrived::LiftArrived(bool proximity_load, bool proximity_drop, bool relay_lift_on) :
    LiftTransition(proximity_load,
                   proximity_drop,
                   relay_lift_on) {

}

bool LiftArrived::binLoadTestEvent() {
  return (m_relayOn && (m_proximityLoad || m_proximityDrop));
}
