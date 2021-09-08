#ifndef BSF_STATEMACHINE__LIFTEVENT_H_
#define BSF_STATEMACHINE__LIFTEVENT_H_

#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QAbstractTransition>

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

class LiftTransition : public QAbstractTransition {
 Q_OBJECT

 public:
  LiftTransition(bool proximityLoad, bool proximityDrop, bool relayLiftOn) :
      m_relayOn(relayLiftOn),
      m_proximityLoad(proximityLoad),
      m_proximityDrop(proximityDrop) {};

 protected:
  bool eventTest(QEvent *e) override {
    qDebug() << "eventTest Lift Transition";

//    if (e->type() != QEvent::Type(QEvent::User + 1)) { // LiftEvent
//      return false;
//    }
//    auto *se = dynamic_cast<LiftEvent *>(e);
    return binLoadTestEvent();

    //return (!m_proximityLoad && m_proximityDrop && !m_relayOn);
  }

  virtual bool binLoadTestEvent() = 0;

  void onTransition(QEvent *) override {
    qDebug() << "on transition...";
  }

 protected:
  bool m_relayOn;
  bool m_proximityLoad;
  bool m_proximityDrop;
};

class LiftIdle : public LiftTransition {
 protected:
 public:
  LiftIdle(bool proximity_load, bool proximity_drop, bool relay_lift_on);

 protected:
  bool binLoadTestEvent() override;
};

class LiftMoving : public LiftTransition {
 protected:
 public:
  LiftMoving(bool proximity_load, bool proximity_drop, bool relay_lift_on);

 protected:
  bool binLoadTestEvent() override;
};

class LiftArrived : public LiftTransition {
 protected:
 public:
  LiftArrived(bool proximity_load, bool proximity_drop, bool relay_lift_on);

 protected:
  bool binLoadTestEvent() override;
};



#endif //BSF_STATEMACHINE__LIFTEVENT_H_
