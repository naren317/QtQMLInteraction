#ifndef VISITORSCREENCONTROLLER_HPP
#define VISITORSCREENCONTROLLER_HPP

#include "abstract_model_visitor.hpp"
#include <QObject>
#include <QQmlApplicationEngine>
#include <QTimer>

class AlgorithmFirst : public AbstractModelVisitor
{
public:
    explicit AlgorithmFirst(const QString& text = "default");
    void accept(AbstractVisitor* visitor) override;
    void update() override;
};

class AlgorithmSecond : public AbstractModelVisitor
{
public:
    explicit AlgorithmSecond(const QString& text = "default");
    void accept(AbstractVisitor* visitor) override;
    void update() override;
};

class AlgorithmThird : public AbstractModelVisitor
{
public:
    explicit AlgorithmThird(const QString& text = "default");
    void accept(AbstractVisitor* visitor) override;
    void update() override;
};


class Visitor : public AbstractVisitor
{
public:
    explicit Visitor() = default;
    void visit(AlgorithmFirst* one) override;
    void visit(AlgorithmSecond* second) override;
    void visit(AlgorithmThird* third) override;
};


class VisitorScreenController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> visitor_model READ getModel WRITE setModel NOTIFY modelChanged)

public:
    explicit VisitorScreenController(QQmlApplicationEngine* engine, QObject* parent = nullptr);
    ~VisitorScreenController();

public slots:
    const QList<QObject*>& getModel() const;
    void setModel(const QList<QObject*>& model);
    void updateModel();

signals:
    void modelChanged();

private:
    void onTimeOut();

private:
    QTimer m_timer;
    const int m_timeout_interval;
    QList<QObject*> m_model;
    Visitor m_visitor;
};

#endif // VISITORSCREENCONTROLLER_HPP
