#include <auroraapp.h>
#include <QtQuick>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.auroraos"));
    application->setApplicationName(QStringLiteral("testAuroraTask"));
    QScopedPointer<QQuickView> view(Aurora::Application::createView());

    enum Status{
        successful = 0,
        error = 1,
        waiting = 2
    };

    Status status = Status::waiting;
    view->rootContext()->setContextProperty("statusValue", static_cast<int>(status));


    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/testAuroraTask.qml")));
    view->show();

    return application->exec();
}
