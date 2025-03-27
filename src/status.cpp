#include "status.h"

Status::Status(QObject *parent) : QObject(parent)
{
}

void Status::sendStatusSuccessful(){
    emit sendStatus(statusOptions::successful);
}

void Status::sendStatusError(){
    emit sendStatus(statusOptions::error);
}

void Status::sendStatusWaiting(){
    emit sendStatus(statusOptions::waiting);
}
