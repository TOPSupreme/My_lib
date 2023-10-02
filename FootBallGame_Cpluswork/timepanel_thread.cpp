
#include "timepanel_thread.h"
#include <QThread>
#include "gamepanel.h"


TimePanel_thread::TimePanel_thread(QObject *parent)
    : QThread{parent}
{

}

TimePanel_thread::~TimePanel_thread()
{

}

void TimePanel_thread::run()
{
    GamePanel *panel=new GamePanel;
    connect(panel,&GamePanel::sendSignal,this,[=](bool start){
        if(start)
        {
            QTimer* timer=new QTimer(this) ;
            connect(timer,&QTimer::timeout,this,[=](){
                int time=0;
                time+=1;
                emit sendSignal_time(time);
            });
            timer->start(10000);
            QTimer::singleShot(900000,timer,&QTimer::stop);
        }
        else ;

    });
}
