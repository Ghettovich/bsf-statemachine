#ifndef BSF_STATEMACHINE_QT_EXAMPLE_STRINGTRANSITION_H_
#define BSF_STATEMACHINE_QT_EXAMPLE_STRINGTRANSITION_H_

#include <QEvent>
#include <QDebug>
#include <QAbstractTransition>

struct StringEvent : public QEvent
{
  StringEvent(const QString &val)
      : QEvent(QEvent::Type(QEvent::User+1)),
        value(val) {}

  QString value;
};

class StringTransition : public QAbstractTransition
{
  Q_OBJECT

 public:
  StringTransition(const QString &value)
      : m_value(value) {}

 protected:
  bool eventTest(QEvent *e) override
  {
    if (e->type() != QEvent::Type(QEvent::User+1)) {// StringEvent
      return false;
    }

    qDebug() << "Got string transition event";
    auto *se = dynamic_cast<StringEvent*>(e);
    return (m_value == se->value);
  }

  void onTransition(QEvent *) override {}

 private:
  QString m_value;
};

#endif //BSF_STATEMACHINE_QT_EXAMPLE_STRINGTRANSITION_H_
