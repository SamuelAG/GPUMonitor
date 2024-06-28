#include "gpumonitorlib.h"
#include <QDebug>

GPUMonitorLib::GPUMonitorLib(QObject *parent)
    : QObject{parent}
{
    qDebug()<<"GPUMonitorLib init"<<Qt::endl;
}

qint32 GPUMonitorLib::temperature()
{
    return 10;
}

qint32 GPUMonitorLib::gpuClock()
{
    return 20;
}

qint32 GPUMonitorLib::memoryClock()
{
    return 30;
}
