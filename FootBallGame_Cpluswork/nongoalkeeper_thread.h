
#ifndef NONGOALKEEPER_THREAD_H
#define NONGOALKEEPER_THREAD_H


#include <QWidget>
#include <QThread>
#include "player.h"

class NonGoalKeeper_thread : public QThread
{
    Q_OBJECT
public:
    explicit NonGoalKeeper_thread(QWidget *parent = nullptr);
    ~NonGoalKeeper_thread();
    void run() override;
    Player cur_NonGoalKeeper;
signals:
    //发送更新当前子线程球员位置的信号
    void sendSignal_update_location(int x,int y);

};

#endif // NONGOALKEEPER_THREAD_H
