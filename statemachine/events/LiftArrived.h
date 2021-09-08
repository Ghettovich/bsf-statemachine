#ifndef BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTARRIVED_H_
#define BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTARRIVED_H_

#include <QAbstractTransition>

class LiftArrived : public QAbstractTransition {
 Q_OBJECT

 public:
  LiftArrived(bool proximity_load, bool proximity_drop, bool relay_lift_on);

 protected:
  bool eventTest(QEvent *e) override;
  void onTransition(QEvent *) override;

 private:
  bool m_relayOn;
  bool m_proximityLoad;
  bool m_proximityDrop;
};

#endif //BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTARRIVED_H_
