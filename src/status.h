#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QDebug>

class Status : public QObject
{
    Q_OBJECT
public:
    explicit Status(QObject *parent = nullptr);

    enum statusOptions {
        successful = 0,
        error = 1,
        waiting = 2
    };

    void sendStatusSuccessful();
    void sendStatusError();
    void sendStatusWaiting();

signals:
    void sendStatus(int value_status);

};

#endif // STATUS_H
