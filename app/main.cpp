#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <gpumonitorlib.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<GPUMonitorLib>("GPUMonitorLib", 1, 0, "GPUMonitorLib");
    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);


    GPUMonitorLib lib;

    return app.exec();
}
