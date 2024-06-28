#ifndef GPUMONITORLIB_H
#define GPUMONITORLIB_H

#include <QObject>

class GPUMonitorLib : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 temperature READ temperature NOTIFY temperatureChanged)
    Q_PROPERTY(qint32 gpuClock READ gpuClock NOTIFY gpuClockChanged)
    Q_PROPERTY(qint32 memoryClock READ memoryClock NOTIFY memoryClockChanged)
public:
    explicit GPUMonitorLib(QObject *parent = nullptr);
    qint32 temperature();
    qint32 gpuClock();
    qint32 memoryClock();
signals:
    void temperatureChanged();
    void gpuClockChanged();
    void memoryClockChanged();
};

#endif // GPUMONITORLIB_H
