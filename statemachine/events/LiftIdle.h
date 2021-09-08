#ifndef BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTIDLE_H_
#define BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTIDLE_H_

#include <QEvent>
#include <QAbstractTransition>

class LiftIdle : public QAbstractTransition {
Q_OBJECT

 public:
  LiftIdle(bool proximityLoad, bool proximityDrop, bool relayLiftOn);

 protected:
  bool eventTest(QEvent *e) override;
  void onTransition(QEvent *) override;

 private:
  bool m_relayOn;
  bool m_proximityLoad;
  bool m_proximityDrop;
};

#endif //BSF_STATEMACHINE_STATEMACHINE_EVENTS_LIFTIDLE_H_
