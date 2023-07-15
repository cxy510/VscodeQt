#include<QGuiApplication>
#include<QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
   // engine.load(QUrl(QStringLiteral(":/resources/main.qml")));
  // engine.load(":/resources/TestJavascript.qml");
   // engine.load(":/resources/main.qml");
    //engine.load(":/resources/TestCase.qml");
    // engine.load(":/resources/appwindow.qml");
     engine.load(":/resources/ClickedableHelloworld.qml");
   if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
