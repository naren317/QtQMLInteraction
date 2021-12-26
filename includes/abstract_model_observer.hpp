#ifndef ABSTRACT_MODEL_OBSERVER_HPP
#define ABSTRACT_MODEL_OBSERVER_HPP

#include <QObject>

class ObjectNotifier;
class AbstractModelObserver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label_name READ getLabelName WRITE setLabelName NOTIFY labelNameChanged)

public:
    explicit AbstractModelObserver(QObject *parent = nullptr, ObjectNotifier* notifier = nullptr);
    virtual void updateLabel() = 0;
    virtual ~AbstractModelObserver() = default;

public slots:
    const QString& getLabelName() const;
    void setLabelName(const QString& label_name);

signals:
    void labelNameChanged();

private:
    QString label_name;
};

#endif // ABSTRACT_MODEL_OBSERVER_HPP
