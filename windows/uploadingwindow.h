#ifndef UPLOADINGWINDOW_H
#define UPLOADINGWINDOW_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

class UploadingWindow : public QObject
{
    Q_OBJECT
public:
    explicit UploadingWindow(QObject *parent = 0);
    ~UploadingWindow();

private:
    QQmlEngine engine;
    QQmlComponent  * component;
    QObject * window;

signals:
    void cancellationAsked();

public slots:
    void show();
    void hide();
    void setProgress(float);
    void setBytesTotal(qint64);
};

#endif // UPLOADINGWINDOW_H
