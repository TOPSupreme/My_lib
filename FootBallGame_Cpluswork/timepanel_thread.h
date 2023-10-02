
#ifndef TIMEPANEL_THREAD_H
#define TIMEPANEL_THREAD_H


#include <QObject>
#include <QThread>
#include <QWaitCondition>


class TimePanel_thread : public QThread
{
    Q_OBJECT
public:
    explicit TimePanel_thread(QObject *parent = nullptr);
    ~TimePanel_thread();
    void run() override;
    QWaitCondition stop;

signals:
    void sendSignal_time(int time);
};

#endif // TIMEPANEL_THREAD_H
