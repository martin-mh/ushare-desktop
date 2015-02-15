#ifndef UPLIMG_H
#define UPLIMG_H

#include <QObject>
#include <QPixmap>
#include <QColor>

#include "core/systemtrayicon.h"
#include "core/screentaker.h"
#include "windows/mainwindow.h"

#include <iostream>

/* This link all modules between them */

class Uplimg : public QObject
{
    Q_OBJECT
public:
    explicit Uplimg(QObject *parent = 0);
    ~Uplimg();
    void start();

    SystemTrayIcon *getSystemTray();

private:
    void initModules();
    void linkConnections();

    SystemTrayIcon * systemTray;
    ScreenTaker * screenTaker;
    MainWindow * mainWindow;


signals:

public slots:
    void startCaptureFullScreenProccess();

    void startCaptureSelectedScreenProccess();
    void captureSelectedScreenProccessFinished(QPixmap);
    void captureSelectedScreenProccessCanceled();
};

#endif // UPLIMG_H
