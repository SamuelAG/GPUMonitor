#include "amdgpusource.h"
#include <ADLX/ADLXHelper/Windows/Cpp/ADLXHelper.h>
#include <ADLX/ADLXHelper/Windows/Cpp/ADLXHelper.cpp>
#include <ADLX/Platform/Windows/WinAPIs.cpp>
#include <ADLX/Include/IPerformanceMonitoring.h>
#include <QDebug>
#include <QTimer>
using namespace adlx;

IADLXPerformanceMonitoringServicesPtr m_perfMonitoringService;
IADLXGPUPtr m_gpu;
ADLXHelper g_ADLXHelp;

void ShowCurrentAllMetrics(IADLXPerformanceMonitoringServicesPtr perfMonitoringServices, IADLXGPUPtr oneGPU);

// Display GPU usage (in %)
std::optional<double> GetGPUUsage(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU usage support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUUsage(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_double usage = 0;
            res = gpuMetrics->GPUUsage(&usage);
            if (ADLX_SUCCEEDED(res))
                return usage;
        }
    }
    return {};
}

// Display GPU clock speed (in MHz)
std::optional<int> GetGPUClockSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU clock speed support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUClockSpeed(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_int gpuClock = 0;
            res = gpuMetrics->GPUClockSpeed(&gpuClock);
            if (ADLX_SUCCEEDED(res))
                return gpuClock;
        }
    }
    return {};
}

// Show GPU VRAM clock speed(MHz)
std::optional<int> GetGPUVRAMClockSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU VRAM clock speed is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAMClockSpeed(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_int memoryClock = 0;
            res = gpuMetrics->GPUVRAMClockSpeed(&memoryClock);
            if (ADLX_SUCCEEDED(res))
                return memoryClock;
        }
    }
    return {};
}

// Show GPU temperature(°C)
std::optional<double> GetGPUTemperature(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU tempetature is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTemperature(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_double temperature = 0;
            res = gpuMetrics->GPUTemperature(&temperature);
            if (ADLX_SUCCEEDED(res))
                return temperature;
        }
    }
    return {};
}

// Show GPU hotspot temperature(°C)
std::optional<double> GetGPUHotspotTemperature(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU hotspot temperature is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUHotspotTemperature(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_double hotspotTemperature = 0;
            res = gpuMetrics->GPUHotspotTemperature(&hotspotTemperature);
            if (ADLX_SUCCEEDED(res))
                return hotspotTemperature;
        }
    }
    return {};
}

// Show GPU power(W)
std::optional<int> GetGPUPower(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU power is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUPower(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_double power = 0;
            res = gpuMetrics->GPUPower(&power);
            if (ADLX_SUCCEEDED(res))
                return power;
        }
    }
    return {};
}

// Show GPU fan speed(RPM)
std::optional<int> GetGPUFanSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU fan speed is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUFanSpeed(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_int fanSpeed = 0;
            res = gpuMetrics->GPUFanSpeed(&fanSpeed);
            if (ADLX_SUCCEEDED(res))
                return fanSpeed;
        }
    }
    return {};
}

// Show GPU VRAM(MB)
std::optional<int> GetGPUVRAM(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU VRAM is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAM(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_int VRAM = 0;
            res = gpuMetrics->GPUVRAM(&VRAM);
            if (ADLX_SUCCEEDED(res))
                return VRAM;
        }
    }
    return {};
}

// Show GPU Voltage(mV)
std::optional<int> GetGPUVoltage(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Get if the GPU voltage is supported
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVoltage(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_int voltage = 0;
            res = gpuMetrics->GPUVoltage(&voltage);
            if (ADLX_SUCCEEDED(res))
                return voltage;
        }
    }
    return {};
}

AmdGPULib::AmdGPULib(QObject *parent)
{
    ADLX_RESULT res_initialize = ADLX_FAIL;

    // Initialize ADLX
    res_initialize = g_ADLXHelp.Initialize();

    if (ADLX_SUCCEEDED(res_initialize))
    {
        // Get Performance Monitoring services
        ADLX_RESULT res = g_ADLXHelp.GetSystemServices()->GetPerformanceMonitoringServices(&m_perfMonitoringService);
        if (ADLX_SUCCEEDED(res))
        {
            IADLXGPUListPtr gpus;
            // Get GPU list
            res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
            if (ADLX_SUCCEEDED(res))
            {
                // Use the first GPU in the list
                res = gpus->At(gpus->Begin(), &m_gpu);
                refreshValues();
                qDebug()<<"ADLX INITIALIZED";
            }
        }
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        refreshValues();
    });
    timer->start(500);

    // Destroy ADLX
    //ADLX_RESULT res = g_ADLXHelp.Terminate();
    //qDebug() << "Destroy ADLX result: " << res << Qt::endl;
}

void AmdGPULib::refreshValues()
{
    // Get GPU metrics support
    IADLXGPUMetricsSupportPtr gpuMetricsSupport;
    ADLX_RESULT res = m_perfMonitoringService->GetSupportedGPUMetrics(m_gpu, &gpuMetricsSupport);

    IADLXAllMetricsPtr allMetrics;
    // Get current All metrics
    ADLX_RESULT res1 = m_perfMonitoringService->GetCurrentAllMetrics(&allMetrics);
    if (ADLX_SUCCEEDED(res1))
    {
        // Get current GPU metrics
        IADLXGPUMetricsPtr gpuMetrics;
        res1 = allMetrics->GetGPUMetrics(m_gpu, &gpuMetrics);
        // Show timestamp and GPU metrics
        if (ADLX_SUCCEEDED(res1) && ADLX_SUCCEEDED(res))
        {
            m_GPUUsage = GetGPUUsage(gpuMetricsSupport, gpuMetrics).value();
            m_GPUClockSpeed = GetGPUClockSpeed(gpuMetricsSupport, gpuMetrics).value();
            m_GPUVRAMClockSpeed = GetGPUVRAMClockSpeed(gpuMetricsSupport, gpuMetrics).value();
            m_GPUTemperature = GetGPUTemperature(gpuMetricsSupport, gpuMetrics).value();
            m_GPUHotspotTemperature = GetGPUHotspotTemperature(gpuMetricsSupport, gpuMetrics).value();
            m_GPUPower = GetGPUPower(gpuMetricsSupport, gpuMetrics).value();
            m_GPUFanSpeed = GetGPUFanSpeed(gpuMetricsSupport, gpuMetrics).value();
            m_GPUVRAM = GetGPUVRAM(gpuMetricsSupport, gpuMetrics).value();
            m_GPUVoltage = GetGPUVoltage(gpuMetricsSupport, gpuMetrics).value();

            qDebug()<< "GPUUsage: "<<GetGPUUsage(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUClockSpeed: "<<GetGPUClockSpeed(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUVRAMClockSpeed: "<<GetGPUVRAMClockSpeed(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUTemperature: "<<GetGPUTemperature(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUHotspotTemperature: "<<GetGPUHotspotTemperature(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUPower: "<<GetGPUPower(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUFanSpeed: "<<GetGPUFanSpeed(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUVRAM: "<<GetGPUVRAM(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;
            qDebug()<< "GPUVoltage: "<<GetGPUVoltage(gpuMetricsSupport, gpuMetrics).value()<<Qt::endl;

            notifyAll();
        }
    } else {
        qDebug()<<"Error "<<res1;
    }
}

void AmdGPULib::notifyAll()
{
    emit GPUUsageChanged();
    emit GPUClockSpeedChanged();
    emit GPUVRAMClockSpeedChanged();
    emit GPUTemperatureChanged();
    emit GPUHotspotTemperatureChanged();
    emit GPUPowerChanged();
    emit GPUFanSpeedChanged();
    emit GPUVRAMChanged();
    emit GPUVoltageChanged();
}

qint64 AmdGPULib::GPUUsage()
{
    return m_GPUUsage;
}

qint64 AmdGPULib::GPUClockSpeed()
{
    return m_GPUClockSpeed;
}

qint64 AmdGPULib::GPUVRAMClockSpeed()
{
    return m_GPUVRAMClockSpeed;
}

qint64 AmdGPULib::GPUTemperature()
{
    return m_GPUTemperature;
}

qint64 AmdGPULib::GPUHotspotTemperature()
{
    return m_GPUHotspotTemperature;
}

qint64 AmdGPULib::GPUPower()
{
    return m_GPUPower;
}

qint64 AmdGPULib::GPUFanSpeed()
{
    return m_GPUFanSpeed;
}

qint64 AmdGPULib::GPUVRAM()
{
    return m_GPUVRAM;
}

qint64 AmdGPULib::GPUVoltage()
{
    return m_GPUVoltage;
}
