#include "gpumonitorlib.h"
#include <QDebug>
GPUMonitorLib::GPUMonitorLib(QObject *parent)
    : QObject{parent}
{
    qDebug()<<"GPUMonitorLib init"<<Qt::endl;
}
