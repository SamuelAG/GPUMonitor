#ifndef GPUMONITORLIB_H
#define GPUMONITORLIB_H

#include <QObject>

class GPUMonitorLib : public QObject
{
    Q_OBJECT
public:
    explicit GPUMonitorLib(QObject *parent = nullptr);

signals:
};

#endif // GPUMONITORLIB_H
