#include <auroraapp.h>
#include <QtQuick>
#include <QQmlContext>
#include "status.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.auroraos"));
    application->setApplicationName(QStringLiteral("testAuroraTask"));
    QScopedPointer<QQuickView> view(Aurora::Application::createView());

    Status *status = new Status(application.data());
    view->rootContext()->setContextProperty("status_object", status);

    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/testAuroraTask.qml")));

    status->sendStatusWaiting();

    view->show();

    return application->exec();
}
