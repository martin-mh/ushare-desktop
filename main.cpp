/* Welcome in uShare !! I'm really happy to see you here :-)
 * Don't be scary about comment or edit the code :-P
 * I hope you a good journey in this code :-) *
*/

/**
 * This file (c) by : - Martin Hammerchmidt alias Imote
 *
 * This file is licensed under a
 * GNU GENERAL PUBLIC LICENSE V3.0
 *
 * See the LICENSE file to learn more.
 *
 * If you have contributed to this file, add your name to authors list.
*/

#include <QApplication>
#include <QString>
#include <QUrl>
#include <QFileInfo>
#include <QtQml>
#include <QIcon>
#include <QSettings>
#include <QVariant>

#ifdef QT_STATIC
#include <QtPlugin>
Q_IMPORT_PLUGIN(QtQuick2PrivateWidgetsPlugin)
#endif

#include "qml/cpp_wrapper/shortcutgetter.h"
#include "ushare.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setQuitOnLastWindowClosed(false);
    app.setWindowIcon(QIcon(":/images/ushare_icon.png"));

    qmlRegisterType<ShortcutGetter>("uShare", 0, 1, "ShortcutGetter");

    QCoreApplication::setOrganizationName("uSquare");
    QCoreApplication::setOrganizationDomain("usquare.io");
    QCoreApplication::setApplicationName("uShare");

    /** DEFAULT CONFIGURATION **/

    QSettings s;

    if(s.value("installed").isNull())
    {
        s.setValue("installed", true);
        s.setValue("copy_link_to_clipboard", true);
        s.setValue("open_file_in_browser", false);
        s.setValue("play_sound", true);
        s.setValue("run_on_startup", false);
        s.setValue("show_notification_window", true);
        s.setValue("show_progress_window", true);
        s.setValue("windows10_notifications", false);
    }

    /** DEFAULT CONFIGURATION END **/

    /** TRANSLATIONS **/

    Settings::init(&app);

    QVariant language = Settings::entry(SettingsKeys::LANGUAGE);

    if(language.isNull())
    {
        QString locale = QLocale::system().name().section('_', 0, 0);
        Settings::setEntry(SettingsKeys::LANGUAGE, locale);
        language = QVariant(locale);
    }

    QTranslator translator;
    translator.load(QString(":/translations/ushare_") + language.toString());
    qApp->installTranslator(&translator);

    /** TRANSLATIONS END **/

    uShare uplimg;
    uplimg.start();

    return app.exec();
}
