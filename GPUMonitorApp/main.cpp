#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <gpumonitorlib.h>
#include <amdgpusource.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<GPUMonitorLib>("GPUMonitorLib", 1, 0, "GPUMonitorLib");
    qmlRegisterType<AmdGPULib>("AmdGPULib", 1, 0, "AmdGPULib");
    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    AmdGPULib amd_lib;


    return app.exec();
}
