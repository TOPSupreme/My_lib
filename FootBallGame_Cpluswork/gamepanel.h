
#ifndef GAMEPANEL_H
#define GAMEPANEL_H


#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QList>
#include "player.h"
#include <QKeyEvent>



namespace Ui
{
   class GamePanel;
}
class GamePanel : public QMainWindow
{
    Q_OBJECT
public:
    explicit GamePanel(QWidget *parent = nullptr);
    ~GamePanel();
    void keyPressEvent(QKeyEvent* event) override;
     QLabel ball;
     int ball_direction;

    Ui::GamePanel * gamepanel;
    QList<Player> NonGoalKeeper;

private:
    //定义两个球队容器，分别用于存放我方球员与Robot球员
    QList<Player> Myteam;
    QList<Player> Robot_team;
    float Myplayer_speed_x;
    float Myplayer_speed_y;
    float Robotplayer_speed_x;
    float Robotplayer_speed_y;
    float ball_speed_x;
    float ball_speed_y;
    int Myplayer_direction;
    int Robotplayer_direction;

signals:
    //自定义信号
    //发送开启计时板的信号
    void sendSignal(bool start);

    //发送当前执球球员位置的信号
    void sendSignal_cur_location(int x,int y);
    //发送当前非执球球员对象的信号
    void SendSignal_NonGoal_keepers(QList<Player> docker);
    //发送当前球队与Robot球队的信号
    void sendSignal_team(QList<Player> myteam,QList<Player> robot_team);

    //发送当前主游戏界面的按键事件
    void sendSignal_keyevent(QKeyEvent* cur_key);

public slots:

    //弹出帮助窗口函数
    void Helper();

    //弹出音量设置窗口函数
    void voiceForce();

    //弹出球员设置窗口函数  replace the players
    void Replace();

    //弹出背景设置窗口函数
    void backGroundSeetings();





};

#endif // GAMEPANEL_H
