#ifndef ABSTRACTMODELVISITOR_HPP
#define ABSTRACTMODELVISITOR_HPP

#include <QObject>

class AlgorithmFirst;
class AlgorithmSecond;
class AlgorithmThird;
class AbstractVisitor
{
public:
    explicit AbstractVisitor() = default;
    virtual void visit(AlgorithmFirst* one) = 0;
    virtual void visit(AlgorithmSecond* second) = 0;
    virtual void visit(AlgorithmThird* third) = 0;
    virtual ~AbstractVisitor() = default;
};

class AbstractModelVisitor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label_name READ getLabelName WRITE setLabelName NOTIFY labelNameChanged)

public:
    explicit AbstractModelVisitor(const QString& text, QObject *parent = nullptr);
    virtual void accept(class AbstractVisitor* visitor) = 0;
    virtual void update() = 0;

public slots:
    void setLabelName(const QString& text);
    const QString& getLabelName() const;

signals:
    void labelNameChanged();

private:
    QString m_label_name;
};

#endif // ABSTRACTMODELVISITOR_HPP
