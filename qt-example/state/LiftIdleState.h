#ifndef BSF_STATEMACHINE_QT_EXAMPLE_STATE_LIFTIDLESTATE_H_
#define BSF_STATEMACHINE_QT_EXAMPLE_STATE_LIFTIDLESTATE_H_

#include <QState>

class LiftIdleState : public QState {
 public:
  explicit LiftIdleState(QState *parent) : QState(parent) {};

 protected:
  void onEntry(QEvent *) override {
    emit sendLiftToLoad();
  }

 signals:
  void sendLiftToLoad();
};

#endif //BSF_STATEMACHINE_QT_EXAMPLE_STATE_LIFTIDLESTATE_H_
