
#include "keypressevent_thread.h"
#include "gamepanel.h"
#include "ui_gamepanel.h"
#include<QPixmap>
#include<QLabel>
#include<QMovie>
#include<QKeyEvent>
#include <QPushButton>
#include <QTimer>
#include "player.h"
#include "gamepanel.h"

KeyPressEvent_thread::KeyPressEvent_thread(QObject *parent)
    : QThread{parent}
{
    GamePanel* panel=new GamePanel;
    connect(panel,&GamePanel::sendSignal_team,this,[=](QList<Player> my_Team,QList<Player> robot_team){
        myTeam=my_Team;
        robot_Team=robot_team;
    });
}

KeyPressEvent_thread::~KeyPressEvent_thread()
{

}


void KeyPressEvent_thread::run()
{
    GamePanel *panel=new GamePanel;
    connect(panel,&GamePanel::sendSignal_keyevent,this,[=](QKeyEvent* event){
    //W键控制当前球员向上移动
    if(event->key()==Qt::Key_W)
    {
        for(int i=0;i<=4;i++)
        {
            if(myTeam[i].status!="current_player")
            {
                int y=myTeam[i].Player_location_y;
                emit sendSignal1(myTeam[i].Player_location_x,y++,i);
                return ;
            }
        }
        return ;
    }
    //S键控制当前球员向下移动
    if(event->key()==Qt::Key_S)
    {
        for(int i=0;i<=4;i++)
        {
            if(myTeam[i].status!="current_player")
            {
                int y=myTeam[i].Player_location_y;
                emit sendSignal1(myTeam[i].Player_location_x,y--,i);
                return ;
            }
        }
        return ;
    }
    //D键控制当前球员向右移动
    if(event->key()==Qt::Key_A)
    {
        for(int i=0;i<=4;i++)
        {
            if(myTeam[i].status!="current_player")
            {
                int x=myTeam[i].Player_location_x;
                emit sendSignal1(x--,myTeam[i].Player_location_y,i);
                return ;
            }
        }
        return ;
    }
    //A键控制当前球员向左移动
    if(event->key()==Qt::Key_D)
    {
        for(int i=0;i<=4;i++)
        {
            if(myTeam[i].status!="current_player")
            {
                int x=myTeam[i].Player_location_x;
                emit sendSignal1(x--,myTeam[i].Player_location_y,i);
                return ;

            }
            else;
        }
        return ;
    }
    //J键控制球员切换
    if(event->key()==Qt::Key_J)
    {
        QPixmap temball(":/game_resources/football_image.gif");
        for(int i=0;i<=4;i++)
        {
            //当我方球员为当前带球球员或我方球员不为当前球员时，禁用J键
            if(myTeam[i].status=="current_player"&&myTeam[i].football_image==temball);
            //否则，切换球员
            else
            {

                if(myTeam[i].status=="current_player"&&i!=4)
                {
                    i++;
                    emit sendSignal4("current_player",i);
                    return ;
                }
                else
                {
                    i=0;
                    emit sendSignal4("current_player",i);
                    return ;
                }
            }
        }
    }
    //K键控制射门
    if(event->key()==Qt::Key_K)
    {
        for(int i=0;i<=4;i++)
        {
            QPixmap temball(":/game_resources/football_image.gif");
            //判断其是否为当前球员执球球员
            if(myTeam[i].status!="current_player"&&myTeam[i].football_image==temball)
            {
                GamePanel panel;
                panel.ball.setPixmap(temball);
                panel.ball_direction=1;
                if(myTeam[i].Player_location_y>panel.gamepanel->Robot_goal->y())
                {
                    if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=185)
                    {
                        ball_speed_x=(panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x);
                        ball_speed_y=(myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(400,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=370)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/2);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/2)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(800,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=555)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/3);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/3)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1200,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=740)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/4);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/4)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1600,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=925)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/5);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=1110)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/6);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/6)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2400,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=1295)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/7);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/7)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2800,timer,&QTimer::stop);
                    }
                    else
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/8);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/8)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(3200,timer,&QTimer::stop);
                    }
                }

                if(myTeam[i].Player_location_y==panel.gamepanel->Robot_goal->y())
                {
                    if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=185)
                    {
                        ball_speed_x=(panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(400,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=370)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/2);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(800,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=555)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/3);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1200,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=740)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/4);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1600,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=925)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/5);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=1110)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/6);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2400,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=1295)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/7);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2800,timer,&QTimer::stop);
                    }
                    else
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/8);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(3200,timer,&QTimer::stop);
                    }
                }

                if(myTeam[i].Player_location_y<panel.gamepanel->Robot_goal->y())
                {
                    if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=185)
                    {
                        ball_speed_x=(panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x);
                        ball_speed_y=(myTeam[i].Player_label_location_y-panel.gamepanel->Robot_goal->y());
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(400,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=370)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/2);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/2);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(800,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=555)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/3);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/3);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(1200,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=740)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/4);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/4);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(1600,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_label_location_x)<=925)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/5);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=1110)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/6);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/6);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);
                        });
                        timer->start(400);
                        QTimer::singleShot(2400,timer,&QTimer::stop);
                    }
                    else if((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)<=1295)
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_location_x)/7);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/7);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2800,timer,&QTimer::stop);
                    }
                    else
                    {
                        ball_speed_x=((panel.gamepanel->Robot_goal->x()-myTeam[i].Player_label_location_x)/8);
                        ball_speed_y=((myTeam[i].Player_location_y-panel.gamepanel->Robot_goal->y())/8);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal2(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(3200,timer,&QTimer::stop);
                    }
                }
            }
            else;
        }
        return ;
    }
    //P键控制传球
    if(event->key()==Qt::Key_P)
    {
        for(int i=0;i<=4;i++)
        {
            GamePanel panel;
            QPixmap temball(":/game_resources/football_image.gif");
            //判断其是否为当前球员执球球员
            if(myTeam[i].status!="current_player"&&myTeam[i].football_image==temball)
            {
                if(i<4)
                {
                    if(myTeam[i].Player_location_x>myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y>myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[i+1].Player_location_x)/5)*(-1);
                        ball_speed_y=((myTeam[i].Player_label_location_y-myTeam[i+1].Player_location_y)/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);

                    }

                    if(myTeam[i].Player_location_x<myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y<myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i+1].Player_location_x-myTeam[i].Player_location_x)/5);
                        ball_speed_y=((myTeam[i+1].Player_location_y-myTeam[i].Player_location_y)/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x>myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y<myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[i+1].Player_location_x)/5)*(-1);
                        ball_speed_y=((myTeam[i+1].Player_location_y-myTeam[i].Player_location_y)/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x>myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y==myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[i+1].Player_location_x)/5)*(-1);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x<myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y>myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[i+1].Player_location_x)/5);
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[i+1].Player_location_y)/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x<myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y==myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[i+1].Player_location_x)/5);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x==myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y>myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=0;
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[i+1].Player_location_y)/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x==myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y<myTeam[i+1].Player_location_y)
                    {
                        ball_speed_x=0;
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[i+1].Player_location_y)/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });;
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x==myTeam[i+1].Player_location_x&&myTeam[i].Player_location_y==myTeam[i+1].Player_location_y)
                    {
                        emit sendSignal3(0,0,i,1);
                    }
                }

                else
                {
                    if(myTeam[i].Player_location_x>myTeam[0].Player_location_x&&myTeam[i].Player_location_y>myTeam[0].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[0].Player_location_x)/5)*(-1);
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[0].Player_location_y)/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x<myTeam[0].Player_location_x&&myTeam[i].Player_location_y<myTeam[0].Player_location_y)
                    {
                        ball_speed_x=((myTeam[0].Player_location_x-myTeam[i].Player_location_x)/5);
                        ball_speed_y=((myTeam[0].Player_location_y-myTeam[i].Player_location_y)/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x>myTeam[0].Player_location_x&&myTeam[i].Player_location_y<myTeam[0].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[0].Player_location_x)/5)*(-1);
                        ball_speed_y=((myTeam[0].Player_location_y-myTeam[i].Player_location_y)/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x>myTeam[0].Player_location_x&&myTeam[i].Player_location_y==myTeam[0].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[0].Player_location_x)/5)*(-1);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x<myTeam[0].Player_location_x&&myTeam[i].Player_location_y>myTeam[0].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[0].Player_location_x)/5);
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[0].Player_location_y)/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x<myTeam[0].Player_location_x&&myTeam[i].Player_location_y==myTeam[0].Player_location_y)
                    {
                        ball_speed_x=((myTeam[i].Player_location_x-myTeam[0].Player_location_x)/5);
                        ball_speed_y=0;
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x==myTeam[0].Player_location_x&&myTeam[i].Player_location_y>myTeam[0].Player_location_y)
                    {
                        ball_speed_x=0;
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[0].Player_location_y)/5)*(-1);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x==myTeam[0].Player_location_x&&myTeam[i].Player_location_y<myTeam[0].Player_location_y)
                    {
                        ball_speed_x=0;
                        ball_speed_y=((myTeam[i].Player_location_y-myTeam[0].Player_location_y)/5);
                        int x,y;
                        x=ball_speed_x+panel.ball.x();
                        y=ball_speed_y+panel.ball.y();
                        QTimer* timer=new QTimer(this);
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal3(x,y,i,timer->isActive());
                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }

                    if(myTeam[i].Player_location_x==myTeam[0].Player_location_x&&myTeam[i].Player_location_y==myTeam[0].Player_location_y)
                    {
                        emit sendSignal3(0,0,i,1);
                    }
                }

            }
        }
    }
    });
}
