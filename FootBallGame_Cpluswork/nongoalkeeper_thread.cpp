
#include "nongoalkeeper_thread.h"
#include "gamepanel.h"

NonGoalKeeper_thread::NonGoalKeeper_thread(QWidget *parent)
    : QThread{parent}
{

}

NonGoalKeeper_thread::~NonGoalKeeper_thread()
{

}

void NonGoalKeeper_thread::run()
{
    GamePanel* panel=new GamePanel;
    //实现gamepanel的sendSignal_cur_location信号与传输当前Nongoalkeeper的目标移动位置的槽函数相关联
    connect(panel,&GamePanel::sendSignal_cur_location,this,[=](int x,int y){
                if(cur_NonGoalKeeper.Player_location_y>y)
                {
                    if((x-cur_NonGoalKeeper.Player_location_x)<=185)
                    {
                        float speed_x=(x-cur_NonGoalKeeper.Player_location_x);
                        float speed_y=(cur_NonGoalKeeper.Player_location_y-y)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(400,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=370)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/2);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/2)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(800,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=555)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/3);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/3)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1200,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=740)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/4);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/4)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1600,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=925)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/5);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/5)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=1110)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/6);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/6)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2400,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=1295)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/7);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/7)*(-1);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2800,timer,&QTimer::stop);
                    }
                    else
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/8);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/8)*(-1);
                        int x,y;
                        x=speed_x+cur_NonGoalKeeper.Player_location_x;
                        y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(x,y);

                        });
                        timer->start(400);
                        QTimer::singleShot(3200,timer,&QTimer::stop);
                    }
                }

                if(cur_NonGoalKeeper.Player_location_y==y)
                {
                    if((x-cur_NonGoalKeeper.Player_location_x)<=185)
                    {
                        float speed_x=(x-cur_NonGoalKeeper.Player_location_x);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(400,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=370)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/2);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(800,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=555)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/3);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1200,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=740)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/4);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1600,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=925)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/5);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=1110)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/6);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2400,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=1295)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_y)/7);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2800,timer,&QTimer::stop);
                    }
                    else
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/8);
                        float speed_y=0;
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(3200,timer,&QTimer::stop);
                    }
                }

                if(cur_NonGoalKeeper.Player_location_y<y)
                {
                    if((x-cur_NonGoalKeeper.Player_location_x)<=185)
                    {
                        float speed_x=(x-cur_NonGoalKeeper.Player_location_x);
                        float speed_y=(cur_NonGoalKeeper.Player_location_y-y);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(400,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=370)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/2);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/2);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(800,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=555)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/3);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/3);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                           emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1200,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=740)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/4);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/4);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(1600,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=925)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/5);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/5);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2000,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=1110)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/6);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/6);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2400,timer,&QTimer::stop);
                    }
                    else if((x-cur_NonGoalKeeper.Player_location_x)<=1295)
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/7);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/7);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(2800,timer,&QTimer::stop);
                    }
                    else
                    {
                        float speed_x=((x-cur_NonGoalKeeper.Player_location_x)/8);
                        float speed_y=((cur_NonGoalKeeper.Player_location_y-y)/8);
                        int X,Y;
                        X=speed_x+cur_NonGoalKeeper.Player_location_x;
                        Y=speed_y+cur_NonGoalKeeper.Player_location_y;
                        QTimer* timer=new QTimer(this) ;
                        connect(timer,&QTimer::timeout,this,[=](){
                            emit sendSignal_update_location(X,Y);

                        });
                        timer->start(400);
                        QTimer::singleShot(3200,timer,&QTimer::stop);
                    }
                }
    });
}
