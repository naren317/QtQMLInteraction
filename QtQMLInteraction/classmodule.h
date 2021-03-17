#ifndef CLASSMODULE_H
#define CLASSMODULE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>

class ClassModule : public QObject // need to inherit from this class if we want to use Qt code from QML
{
    /*
     * @brief following is the macro which calls the meta object compiler, that converts the Qt code into the standard c++ code for the
     * c++ compiler to parse
    */
    Q_OBJECT

    /*
     * @brief following is the Q_PROPERTY which will be passed to the QML from the cpp
     * the signal string_changed calls the getString method
    */
    Q_PROPERTY(QString hello_world READ getString WRITE setString NOTIFY string_changed);

    /*
     * @brief following is the pImpl implementation structure, impl is the structure
    */
    struct impl;
    /*
     * @brief following is the smart pointer instantiation of the implementation class
    */
    std::shared_ptr<impl> pImpl;

public:
    /*
     * @brief the ctor of our data handler class
    */
    ClassModule(QQmlApplicationEngine *engine = nullptr, const QUrl* const url = nullptr, QObject *parent = nullptr);

public slots:
    /*
     * @brief following is the getter method which is called when the signal of hello_world is changed
    */
    QString getString() const;

    /*
     * @brief following is the setter method which needs to be called when the string to the QML needs to be changed
    */
    void setString(const QString& hello_string);

signals:
    /*
     * @brief following is the signal which needs to be emitted whenever we change the hello_world string
    */
    void string_changed();
};

#endif // CLASSMODULE_H
