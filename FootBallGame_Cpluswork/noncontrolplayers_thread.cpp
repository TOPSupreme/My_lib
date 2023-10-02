
#include "noncontrolplayers_thread.h"
#include "gamepanel.h"
#include "nongoalkeeper_thread.h"
#include <QWindow>
#include <QVBoxLayout>


NonControlPlayers_thread::NonControlPlayers_thread(QObject *parent)
    : QThread{parent}
{
    GamePanel* panel=new GamePanel;
    //连接GamePanel的NonGoalKeeper docker信号与对应槽函数，完成对应成员的初始化
    connect(panel,&GamePanel::SendSignal_NonGoal_keepers,this,[=](QList<Player> tempdocker){
        docker=tempdocker;
    });
}

NonControlPlayers_thread::~NonControlPlayers_thread()
{

}

void NonControlPlayers_thread::run()
{
    //创建int型的num对象，用于存储对应docker容器中NonGoalKeeper对象的数量
    int num;
    num=docker.count();

    //初始化每个子线程的cur_NonGoalKeeper对象
    if(num==8)
    {
       for(int i=1;i<=8;i++)
       {
          NonGoalKeeper_thread child_thread;
          child_thread.cur_NonGoalKeeper=docker[i];
          child_thread.start();
       }
    }

    if(num==9)
    {
       for(int i=1;i<=9;i++)
       {
          NonGoalKeeper_thread child_thread;
          child_thread.cur_NonGoalKeeper=docker[i];
          child_thread.start();
       }
    }

}




