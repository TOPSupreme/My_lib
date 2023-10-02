
#ifndef KEYPRESSEVENT_THREAD_H
#define KEYPRESSEVENT_THREAD_H


#include <QThread>
#include<QKeyEvent>
#include<QLabel>
#include <QWaitCondition>
#include "player.h"
#include "gamepanel.h"



class KeyPressEvent_thread : public QThread
{
    Q_OBJECT
public:
    explicit KeyPressEvent_thread(QObject *parent = nullptr);
    ~KeyPressEvent_thread();
    QWaitCondition stop;
    QList<Player> myTeam;
    QList<Player> robot_Team;
    GamePanel panel;

protected:
    void run() override;
private:
    float ball_speed_x;
    float ball_speed_y;

signals:
    //自定义信号
    //发送控制W A S D 键的信号 order传球员序号
    void sendSignal1(int x,int y,int order);
    //发送控制球运动的信号 K键射门
    void sendSignal2(int x,int y);
    //发送控制 P键 传球的信号  x y传球移动的目标位置 pixmap传递球的图像 order传递label_keeper序号
    void sendSignal3(int x,int y,int order,bool timer_isActive);
    //发送控制 J键 传球的信号
    void sendSignal4(QString str,int order);


};

#endif // KEYPRESSEVENT_THREAD_H
