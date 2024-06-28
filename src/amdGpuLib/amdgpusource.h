#ifndef AMDGPULIB_H
#define AMDGPULIB_H

#include <QObject>

class AmdGPULib : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 GPUUsage READ GPUUsage NOTIFY GPUUsageChanged)
    Q_PROPERTY(qint64 GPUClockSpeed READ GPUClockSpeed NOTIFY GPUClockSpeedChanged)
    Q_PROPERTY(qint64 GPUVRAMClockSpeed READ GPUVRAMClockSpeed NOTIFY GPUVRAMClockSpeedChanged)
    Q_PROPERTY(qint64 GPUTemperature READ GPUTemperature NOTIFY GPUTemperatureChanged)
    Q_PROPERTY(qint64 GPUHotspotTemperature READ GPUHotspotTemperature NOTIFY GPUHotspotTemperatureChanged)
    Q_PROPERTY(qint64 GPUPower READ GPUPower NOTIFY GPUPowerChanged)
    Q_PROPERTY(qint64 GPUFanSpeed READ GPUFanSpeed NOTIFY GPUFanSpeedChanged)
    Q_PROPERTY(qint64 GPUVRAM READ GPUVRAM NOTIFY GPUVRAMChanged)
    Q_PROPERTY(qint64 GPUVoltage READ GPUVoltage NOTIFY GPUVoltageChanged)
public:
    explicit AmdGPULib(QObject *parent = nullptr);
    qint64 GPUUsage();
    qint64 GPUClockSpeed();
    qint64 GPUVRAMClockSpeed();
    qint64 GPUTemperature();
    qint64 GPUHotspotTemperature();
    qint64 GPUPower();
    qint64 GPUFanSpeed();
    qint64 GPUVRAM();
    qint64 GPUVoltage();
    void refreshValues();
private:
    qint64 m_GPUUsage;
    qint64 m_GPUClockSpeed;
    qint64 m_GPUVRAMClockSpeed;
    qint64 m_GPUTemperature;
    qint64 m_GPUHotspotTemperature;
    qint64 m_GPUPower;
    qint64 m_GPUFanSpeed;
    qint64 m_GPUVRAM;
    qint64 m_GPUVoltage;
    void notifyAll();
signals:
    void GPUUsageChanged();
    void GPUClockSpeedChanged();
    void GPUVRAMClockSpeedChanged();
    void GPUTemperatureChanged();
    void GPUHotspotTemperatureChanged();
    void GPUPowerChanged();
    void GPUFanSpeedChanged();
    void GPUVRAMChanged();
    void GPUVoltageChanged();
};

#endif // AMDGPULIB_H
