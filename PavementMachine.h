#ifndef BSF_STATEMACHINE__PAVEMENTMACHINE_H_
#define BSF_STATEMACHINE__PAVEMENTMACHINE_H_

#include <QObject>
#include <QDebug>
#include <QStateMachine>

class PavementMachine : public QObject {
  Q_OBJECT

 public:
  PavementMachine();

  void sendLiftToLoad();

 private:
  QStateMachine machine;
};

#endif //BSF_STATEMACHINE__PAVEMENTMACHINE_H_
