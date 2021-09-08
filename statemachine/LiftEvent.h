#ifndef BSF_STATEMACHINE__LIFTEVENT_H_
#define BSF_STATEMACHINE__LIFTEVENT_H_

#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QAbstractTransition>

class LiftTransition : public QAbstractTransition {
 Q_OBJECT

 public:
  LiftTransition(bool proximityLoad, bool proximityDrop, bool relayLiftOn);

 protected:
  bool eventTest(QEvent *e) override;
  virtual bool binLoadTestEvent() = 0;

  void onTransition(QEvent *) override;

 protected:
  bool m_relayOn;
  bool m_proximityLoad;
  bool m_proximityDrop;
};

#endif //BSF_STATEMACHINE__LIFTEVENT_H_
