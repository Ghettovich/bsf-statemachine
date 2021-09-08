#ifndef BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTEVENTDATA_H_
#define BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTEVENTDATA_H_

struct LiftEvent : public QEvent {
  LiftEvent(bool proximityLoad, bool proximityDrop, bool relayLiftOn) :
      QEvent(QEvent::Type(QEvent::User + 1)),
      relayLiftOn(relayLiftOn),
      proximityLoad(proximityLoad),
      proximityDrop(proximityDrop) {};

  bool relayLiftOn;
  bool proximityLoad;
  bool proximityDrop;
};

#endif //BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTEVENTDATA_H_
