#ifndef ABSTRACTMODELDESIGNPATTERNS_HPP
#define ABSTRACTMODELDESIGNPATTERNS_HPP

#include <QObject>

class AbstractModelDesignPatterns : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString design_name READ getDesignName WRITE setDesignName NOTIFY designNameChanged)

public:
    AbstractModelDesignPatterns(QObject* parent = nullptr);
    virtual ~AbstractModelDesignPatterns() = default;
    Q_INVOKABLE virtual void loadPattern() = 0;

public slots:
    const QString& getDesignName() const;
    void setDesignName(const QString& name);

signals:
    void designNameChanged();

protected:
    QString design_name;
};

#endif // ABSTRACTMODELDESIGNPATTERNS_HPP
