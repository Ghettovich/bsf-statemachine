#ifndef BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTMOVING_H_
#define BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTMOVING_H_

#include <QAbstractTransition>

class LiftMoving  : public QAbstractTransition {
 Q_OBJECT

 public:
  LiftMoving(bool proximity_load, bool proximity_drop, bool relay_lift_on);

 protected:
  bool eventTest(QEvent *e) override;
  void onTransition(QEvent *) override;

 private:
  bool m_relayOn;
  bool m_proximityLoad;
  bool m_proximityDrop;
};

#endif //BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTMOVING_H_
