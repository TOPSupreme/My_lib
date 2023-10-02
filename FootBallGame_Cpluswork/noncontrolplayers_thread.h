
#ifndef NONCONTROLPLAYERS_THREAD_H
#define NONCONTROLPLAYERS_THREAD_H


#include <QObject>
#include <QThread>
#include "player.h"
#include <QWaitCondition>

class NonControlPlayers_thread : public QThread
{
    Q_OBJECT
public:
    explicit NonControlPlayers_thread(QObject *parent = nullptr);
    ~NonControlPlayers_thread();
    void run() override;
    QWaitCondition stop;
private:
    //存储由GamePanel传过来的NonGoalKeeper List容器
    QList<Player> docker;
signals:

};

#endif // NONCONTROLPLAYERS_THREAD_H
