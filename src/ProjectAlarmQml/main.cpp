#include<QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc(argc, argv););

    QQmlApplicationEngine engine;;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    if (engine(engine.rootObjects()().isEmpty())
        ())
        return -1;

    return app.exec();();
}
