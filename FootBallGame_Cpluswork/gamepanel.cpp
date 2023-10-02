
#include "gamepanel.h"
#include "ui_gamepanel.h"
#include<QPixmap>
#include<QLabel>
#include<QMovie>
#include<QKeyEvent>
#include"helperpanel.h"
#include "voicesettings.h"
#include "rolesettings.h"
#include "background_seetings.h"
#include <QPushButton>
#include <QTimer>
#include "keypressevent_thread.h"
#include "timepanel_thread.h"
#include <QMutex>
#include "victory.h"
#include "failure.h"
#include "tie.h"
#include "player.h"
#include "headimage_settings.h"
#include "rolesettings.h"
#include "noncontrolplayers_thread.h"
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlDatabase>

GamePanel::GamePanel(QWidget *parent)
    : QMainWindow{parent},
    gamepanel(new Ui::GamePanel)
{

    gamepanel->setupUi(this);
    QPixmap field_background(":/game_resources/football_Field_image2(2).jpg");
    gamepanel->Gamepanel_label->setPixmap(field_background);

    //设置球员的默认选择
    //我方球员
    QPixmap myplayer1(":/game_resources/gameplayer_image2_Messi(1).png");
    gamepanel->MyP1->setPixmap(myplayer1);
    QPixmap myplayer2(":/game_resources/gameplayer_image6_Neymar(1).png");
    gamepanel->MyP2->setPixmap(myplayer2);
    QPixmap myplayer3(":/game_resources/gameplayer_image3_Suarez(1).png");
    gamepanel->MyP3->setPixmap(myplayer3);
    QPixmap myplayer4(":/game_resources/gameplayer_image4_Maradona(1).png");
    gamepanel->MyP4->setPixmap(myplayer4);
    QPixmap myplayer5(":/game_resources/gameplayer_image12_Matinez(1).png");
    gamepanel->MyP5->setPixmap(myplayer5);

    //Robot球员
    QPixmap robotplayer1(":/game_resources/gameplayer_image1_Cristiano(1).png");
    gamepanel->Robot_P1->setPixmap(robotplayer1);
    QPixmap robotplayer2(":/game_resources/gameplayer_image7_Mbappe(1).png");
    gamepanel->Robot_P2->setPixmap(robotplayer2);
    QPixmap robotplayer3(":/game_resources/gameplayer_image10_LukaModvic(1).png");
    gamepanel->Robot_P3->setPixmap(robotplayer3);
    QPixmap robotplayer4(":/game_resources/gameplayer_image5_Flix(1).png");
    gamepanel->Robot_P4->setPixmap(robotplayer4);
    QPixmap robotplayer5(":/game_resources/gameplayer_image14_Courtois(1).png");
    gamepanel->Robot_P5->setPixmap(robotplayer5);

    //设置默认头像
    QPixmap default_myheadimage(":/game_resources/headimage_test2(1).png");
    gamepanel->Myheadimage_label->setPixmap(default_myheadimage);
    QPixmap default_Robotheadimage(":/game_resources/headimage_test1(1).png");
    gamepanel->Robotheadimage_label->setPixmap(default_Robotheadimage);

    //默认发球方为我方P1球员，在MyPlayer1 Widget窗口中设置足球的动态播放图像
    QPixmap temball(":/game_resources/football_image2(1).jpg");
    gamepanel->My_goal_keeper1->setPixmap(temball);

    QPixmap goal1(":/game_resources/goal(1).png");
    gamepanel->My_goal->setPixmap(goal1);
    QPixmap goal2(":/game_resources/goal(2).png");
    gamepanel->Robot_goal->setPixmap(goal2);

    //初始化Current_goal_keeper
    //在本游戏中我们默认都是我方P1球员发球
    gamepanel->My_goal_keeper1->setObjectName("current_goal_keeper");

    //初始化球队容器
    //初始化我方球队
    QList<Player>::iterator cur_Myplayer=Myteam.begin();
    for(int i=0;i<=4;i++)
    {
        if(i==0)
        {
            //默认为我方一号球员发球
            Player player1;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image2_Messi(1).png");
            player1.player_image=tempPlayer_image;
            QPixmap temball(":/game_resources/football_image.gif");
            player1.football_image=temball;
            //初始化球员位置
            player1.Player_location_x=590;
            player1.Player_location_y=43;
            Myteam.insert(cur_Myplayer,player1);
        }
        else if(i==1)
        {
            Player player2;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image6_Neymar(1).png");
            player2.player_image=tempPlayer_image;
            //初始化球员位置
            player2.Player_location_x=590;
            player2.Player_location_y=600;
            Myteam.insert(cur_Myplayer+1,player2);
        }
        else if(i==2)
        {
            Player player3;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image3_Suarez(1).png");
            player3.player_image=tempPlayer_image;
            //初始化球员位置
            player3.Player_location_x=370;
            player3.Player_location_y=340;
            Myteam.insert(cur_Myplayer+2,player3);
        }
        else if(i==3)
        {
            Player player4;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image4_Maradona(1).png");
            player4.player_image=tempPlayer_image;
            //初始化球员位置
            player4.Player_location_x=370;
            player4.Player_location_y=710;
            Myteam.insert(cur_Myplayer+3,player4);
        }
        else
        {
            Player player5;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image12_Matinez(1).png");
            player5.player_image=tempPlayer_image;
            //初始化球员位置
            player5.Player_location_x=90;
            player5.Player_location_y=550;
            Myteam.insert(cur_Myplayer+4,player5);
        }

    }
    //初始化Robot球队容器
    QList<Player>::iterator cur_Robot=Robot_team.begin();
    for(int i=0;i<=4;i++)
    {
        if(i==0)
        {
            Player player2;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image7_Mbappe(1).png");
            player2.player_image=tempPlayer_image;
            //初始化球员位置
            player2.Player_location_x=920;
            player2.Player_location_y=430;
            Myteam.insert(cur_Robot,player2);
        }

        else if(i==1)
        {
            Player player2;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image1_Cristiano(1).png");
            player2.player_image=tempPlayer_image;
            //初始化球员位置
            player2.Player_location_x=920;
            player2.Player_location_y=600;
            Myteam.insert(cur_Robot+1,player2);
        }
        else if(i==2)
        {
            Player player3;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image10_LukaModvic(1).png");
            player3.player_image=tempPlayer_image;
            //初始化球员位置
            player3.Player_location_x=1080;
            player3.Player_location_y=340;
            Myteam.insert(cur_Robot+2,player3);
        }
        else if(i==3)
        {
            Player player4;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image5_Flix(1).png");
            player4.player_image=tempPlayer_image;
            //初始化球员位置
            player4.Player_location_x=1100;
            player4.Player_location_y=710;
            Myteam.insert(cur_Robot+3,player4);
        }
        else
        {
            Player player5;
            QPixmap tempPlayer_image(":/game_resources/gameplayer_image14_Courtois(1).png");
            player5.player_image=tempPlayer_image;
            //初始化球员位置
            player5.Player_location_x=1430;
            player5.Player_location_y=550;
            Myteam.insert(cur_Robot+4,player5);
        }
    }


    //初始化NonGoalKeeper 容器
    //当执球球员在Myteam中时
    if(Myteam[0].football_image==temball)
    {
        for(int i=1;i<=4;i++)
        {
          if(Myteam[i].status!="current_player")
           NonGoalKeeper.push_back(Myteam[i]);
        }
        for(int i=0;i<=4;i++)
        {
           NonGoalKeeper.push_back(Robot_team[i]);
        }

    }

    for(int i=1;i<4;i++)
    {
    if(Myteam[i].football_image==temball)
    {
           for(i-=1;i>=0;i--)
           {
               if(Myteam[i].status!="curreant_player")
               NonGoalKeeper.push_back(Myteam[i]);
           }
           for(i+=1;i<=4;i++)
           {
               if(Myteam[i].status!="current_player")
               NonGoalKeeper.push_back(Myteam[i]);
           }
           for(int i=0;i<=4;i++)
           {
               NonGoalKeeper.push_back(Robot_team[i]);
           }
    }
    }

    if(Myteam[4].football_image==temball)
    {
    for(int i=3;i>=0;i--)
    {
           if(Myteam[i].status!="current_player")
           NonGoalKeeper.push_back(Myteam[i]);
    }
    for(int i=0;i<=4;i++)
    {
           NonGoalKeeper.push_back(Robot_team[i]);
    }
    }

    //当执球球员在Rbot_team中时
    if(Robot_team[0].football_image==temball)
    {
    for(int i=1;i<=4;i++)
    {
           NonGoalKeeper.push_back(Robot_team[i]);
    }
    for(int i=0;i<=4;i++)
    {
           NonGoalKeeper.push_back(Myteam[i]);
    }

    for(int i=1;i<4;i++)
    {
           if(Robot_team[i].football_image==temball)
           {
           for(i-=1;i>=0;i--)
           {

                   NonGoalKeeper.push_back(Robot_team[i]);
           }
           for(i+=1;i<=4;i++)
           {
               if(Myteam[i].status!="current_player")
                   NonGoalKeeper.push_back(Robot_team[i]);
           }
           for(int i=0;i<=4;i++)
           {
               NonGoalKeeper.push_back(Myteam[i]);
           }
           }
    }

    if(Robot_team[4].football_image==temball)
    {
           for(int i=3;i>=0;i--)
           {
               NonGoalKeeper.push_back(Robot_team[i]);
           }
           for(int i=0;i<=4;i++)
           {
           NonGoalKeeper.push_back(Myteam[i]);
           }
    }

    }
    //初始化相关私有数据成员
    Myplayer_speed_x=0;
    Myplayer_speed_y=0;
    Robotplayer_speed_x=0;
    Robotplayer_speed_y=0;

    Robotplayer_direction=-1;
    ball_direction=1;
    ball_speed_x=0;
    ball_speed_y=0;

    //连接相关信号与槽函数，完成对应响应
    //连接voiceSettings action与voiceForce槽函数，完成音量设置点击响应
    connect(gamepanel->actionvoiceforce,&QAction::triggered,this,&GamePanel::voiceForce);
    //连接与Replace()槽函数，完成球员替换点击响应
    connect(gamepanel->actionreplace_the_soccer_player,&QAction::triggered,this,&GamePanel::Replace);
    //连接backgroundSettings action与backGroundsettings()槽函数，完成背景更换响应
    connect(gamepanel->actionbackground,&QAction::triggered,this,&GamePanel::backGroundSeetings);
    //连接helper——action与helper()槽函数，完成帮助面板显示响应
    connect(gamepanel->helper_action,&QAction::triggered,this,&GamePanel::Helper);



    //创建子线程KeyPressEventThread对象
    KeyPressEvent_thread* thread1=new KeyPressEvent_thread(this);
    //启动线程
    thread1->start();
    //子线程的对应信号与主线程的槽函数
    //连接Signal1与对应槽函数 玩家控制球员移动
    connect(thread1,&KeyPressEvent_thread::sendSignal1,this,[=](int i){
        QMovie * movie=new QMovie(this);//用来播放gif动态图片
        movie->setFileName(":/game_resources/football_image.gif");
        movie->start();
        //创建临时球员窗口
        QWidget cur_player(this);
        cur_player.setGeometry(Myteam[i].Widget_width,Myteam[i].Widget_height,Myteam[i].Player_location_x,Myteam[i].Player_label_location_y);
        //创建临时球员label
        QLabel player_label(&cur_player);
        player_label.setGeometry(Myteam[i].Player_label_width,Myteam[i].Player_label_height,Myteam[i].Player_label_location_x,Myteam[i].Player_label_location_y);
        player_label.setPixmap(Myteam[i].player_image);
        //创建临时球label
        QLabel ball_label(&cur_player);
        ball_label.setGeometry(Myteam[i].Ball_label_width,Myteam[i].Ball_label_height,Myteam[i].Ball_label_location_x,Myteam[i].Ball_label_location_y);
        ball_label.setMovie(movie);
    });

    //连接Signal2与对应槽函数 控制球的移动
    connect(thread1,&KeyPressEvent_thread::sendSignal2,this,[=](int x,int y){
        ball.setGeometry(20,20,x,y);
        QMovie * movie=new QMovie(this);//用来播放gif动态图片
        movie->setFileName(":/game_resources/football_image.gif");
        movie->start();
        ball.setMovie(movie);
    });

    //连接Signal3与对应槽函数 控制P键的传球
    connect(thread1,&KeyPressEvent_thread::sendSignal3,this,[=](int x,int y,int i,bool is_timerActive){
        //将对应传球球员的足球Pixmap对象像素清空
        Myteam[i].football_image.fill(Qt::transparent);
        //创建临时球员窗口
        QWidget cur_player(this);
        cur_player.setGeometry(Myteam[i].Widget_width,Myteam[i].Widget_height,Myteam[i].Player_location_x,Myteam[i].Player_label_location_y);
        //创建临时球员label
        QLabel player_label(&cur_player);
        player_label.setGeometry(Myteam[i].Player_label_width,Myteam[i].Player_label_height,Myteam[i].Player_label_location_x,Myteam[i].Player_label_location_y);
        player_label.setPixmap(Myteam[i].player_image);
        //创建临时球label
        QLabel ball_label(&cur_player);
        ball_label.setGeometry(Myteam[i].Ball_label_width,Myteam[i].Ball_label_height,Myteam[i].Ball_label_location_x,Myteam[i].Ball_label_location_y);
        ball_label.setPixmap(Myteam[i].football_image);
        ball.setGeometry(20,20,x,y);
        QMovie * movie=new QMovie(this);//用来播放gif动态图片
        movie->setFileName(":/game_resources/football_image.gif");
        movie->start();
        ball.setMovie(movie);
        //如果计时器终止，则代表球已经运动到了指定位置，则将target球员的footballimage设置为
        if(is_timerActive)
        {
            //创建临时球员窗口
            QWidget cur_player(this);
            cur_player.setGeometry(Myteam[i+1].Widget_width,Myteam[i+1].Widget_height,Myteam[i+1].Player_location_x,Myteam[i+1].Player_label_location_y);
            //创建临时球员label
            QLabel player_label(&cur_player);
            player_label.setGeometry(Myteam[i+1].Player_label_width,Myteam[i+1].Player_label_height,Myteam[i+1].Player_label_location_x,Myteam[i+1].Player_label_location_y);
            player_label.setPixmap(Myteam[i+1].player_image);
            //创建临时球label
            QLabel ball_label(&cur_player);
            ball_label.setGeometry(Myteam[i+1].Ball_label_width,Myteam[i+1].Ball_label_height,Myteam[i+1].Ball_label_location_x,Myteam[i+1].Ball_label_location_y);
            ball_label.setMovie(movie);
        }

    });

    //连接Signal4与对应槽函数 J键控制球员的切换
    connect(thread1,&KeyPressEvent_thread::sendSignal4,this,[=](QString str,int i){
        Myteam[i].status=str;
    });


    //创建timepanel_thread子线程对象
    TimePanel_thread* thread2=new TimePanel_thread;
    connect(thread2,&TimePanel_thread::sendSignal_time,this,[=](int time){
        if(time<95)
        {
        QString timeStr=QString::number(time)+":00";
        //调用函数，将实时时间更新到游戏界面上
        this->gamepanel->Timer_label->setText(timeStr);
        }
        else{
        QString timeStr=QString::number(time)+":00";
        //调用函数，将实时时间更新到游戏界面上
        this->gamepanel->Timer_label->setText(timeStr);
        bool ok=true;
        if(gamepanel->Robotscore_lineedit->text().toInt(&ok)<gamepanel->Myscore_lineedit->text().toInt(&ok))
        {
            Victory victor;
            victor.show();
            QDateTime currentDateTime = QDateTime::currentDateTime(); // 获取当前系统时间
            QString cur_time=currentDateTime.toString(Qt::ISODate);
            QSqlQuery query;
            query.prepare("INSERT INTO battledata (BattleDate, Myscore,RobotScore)VALUES (:battledate, :myscore,:robotscore)");
            query.bindValue(":battledate",cur_time);
            query.bindValue(":myscore", gamepanel->Myscore_lineedit->text());
            query.bindValue(":robotscore",gamepanel->Robotscore_lineedit->text());
            if(!query.exec())
            {
               qDebug() << "Failed to insert time!";
            }
            else
            {
               qDebug() << "Time inserted successfully!";
            }

        }
        else if(gamepanel->Robotscore_lineedit->text().toInt(&ok)>gamepanel->Myscore_lineedit->text().toInt(&ok)){
            Failure* fail=new Failure;
            fail->show();
            QDateTime currentDateTime = QDateTime::currentDateTime(); // 获取当前系统时间
            QString cur_time=currentDateTime.toString(Qt::ISODate);
            QSqlQuery query;
            query.prepare("INSERT INTO battledata (BattleDate, Myscore,RobotScore)VALUES (:battledate, :myscore,:robotscore)");
            query.bindValue(":battledate",cur_time);
            query.bindValue(":myscore", gamepanel->Myscore_lineedit->text());
            query.bindValue(":robotscore",gamepanel->Robotscore_lineedit->text());
            if(!query.exec())
            {
               qDebug() << "Failed to insert time!";
            }
            else
            {
               qDebug() << "Time inserted successfully!";
            }
        }
        else{
            Tie* tie=new Tie;
            tie->show();
            QDateTime currentDateTime = QDateTime::currentDateTime(); // 获取当前系统时间
            QString cur_time=currentDateTime.toString(Qt::ISODate);
            QSqlQuery query;
            query.prepare("INSERT INTO battledata (BattleDate, Myscore,RobotScore)VALUES (:battledate, :myscore,:robotscore)");
            query.bindValue(":battledate",cur_time);
            query.bindValue(":myscore", gamepanel->Myscore_lineedit->text());
            query.bindValue(":robotscore",gamepanel->Robotscore_lineedit->text());
            if(!query.exec())
            {
               qDebug() << "Failed to insert time!";
            }
            else
            {
               qDebug() << "Time inserted successfully!";
            }
        }
        }
    });

    //创建NongoalKeepers_thread子线程对象，并启动线程，完成非玩家控制球员的自主运动
    NonControlPlayers_thread* thread3=new NonControlPlayers_thread;
    thread3->start();
    //连接stop action 与对应线程的wait函数 完成线程的终止操作
    //Non_goal_keeper 待补充
    connect(gamepanel->stop_action,&QAction::triggered,this,[=](){
         QMutex mutex;
        thread1->stop.wait(&mutex);
        thread2->stop.wait(&mutex);
        thread3->stop.wait(&mutex);
    });

    //连接continue action与对应线程的wakeAll函数 完成线程的暂停后的继续操作
    connect(gamepanel->continue_action,&QAction::triggered,this,[=](){
        thread1->stop.wakeAll();
        thread2->stop.wakeAll();
        thread3->stop.wakeAll();
    });

    //连接restart action与对应槽函数，完成线程的重启操作,进而达到游戏重启的效果
    connect(gamepanel->continue_action,&QAction::triggered,this,[=](){
        this->close();
        this->show();
        QMutex mutex;
        thread1->stop.wait(&mutex);
        thread2->stop.wait(&mutex);
        thread3->stop.wait(&mutex);
        thread1->start();
        thread2->start();
        thread3->start();
    });

    //实现当前球员位置信号的发送
    QTimer* timer=new QTimer(this) ;
    connect(timer,&QTimer::timeout,this,[=](){
        for(int i=0;i<=4;i++)
            {
            if(Myteam[i].football_image==temball)
                emit sendSignal_cur_location(Myteam[i].Player_location_x,Myteam[i].Player_location_y);
            if(Myteam[i].football_image==temball)
                emit sendSignal_cur_location(Myteam[i].Player_location_x,Myteam[i].Player_location_y);
        }
    });
    //一毫秒发一次，实现信号的实时传输，使游戏运行更加流畅，Nongoalkeeper球员位置的实时更新
    timer->start(1);
    QTimer::singleShot(90000,timer,&QTimer::stop);

    //实现当前非执球球员容器的传输发送的信号与对应槽函数的连接
    QTimer* timer1=new QTimer(this);
    connect(timer1,&QTimer::timeout,this,[=](){
        emit SendSignal_NonGoal_keepers(NonGoalKeeper);
    });
    //一毫秒发一次，实现信号的实时传输，使游戏运行更加流畅，实现非球员容器的实时同步更新，保证游戏运行的准确性
    timer1->start(1);
    QTimer::singleShot(90000,timer1,&QTimer::stop);

    //实现team容器的实时信号的同步传输，保证游戏运行过程中数据的稳定性
    QTimer* timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,[=](){
        emit sendSignal_team(Myteam,Robot_team);
    });
    //一毫秒发一次，实现信号的实时传输，使游戏运行更加流畅，实现非球员容器的实时同步更新，保证游戏运行的准确性
    timer2->start(1);
    QTimer::singleShot(90000,timer2,&QTimer::stop);

    //连接headimage_settings的图像信号，完成用户头像设置
    HeadImage_Settings* set_headimage=new HeadImage_Settings;
    connect(set_headimage,&HeadImage_Settings::sendSignal,this,[=](QPixmap headimage){
        gamepanel->Myheadimage_label->setPixmap(headimage);
    });

    //连接rolesettings的图像信号，完成角色图像的替换
    RoleSettings* setRole=new RoleSettings;
    connect(setRole,&RoleSettings::sendSignal,this,[=](QPixmap role_image,int order){
        if(order<=5)
        {
            Myteam[order].player_image=role_image;
            //创建临时球员窗口
            QWidget cur_player(this);
            cur_player.setGeometry(Myteam[order].Widget_width,Myteam[order].Widget_height,Myteam[order].Player_location_x,Myteam[order].Player_label_location_y);
            //创建临时球员label
            QLabel player_label(&cur_player);
            player_label.setGeometry(Myteam[order].Player_label_width,Myteam[order].Player_label_height,Myteam[order].Player_label_location_x,Myteam[order].Player_label_location_y);
            player_label.setPixmap(Myteam[order].player_image);
            //创建临时球label
            QLabel ball_label(&cur_player);
            ball_label.setGeometry(Myteam[order].Ball_label_width,Myteam[order].Ball_label_height,Myteam[order].Ball_label_location_x,Myteam[order].Ball_label_location_y);
            ball_label.setPixmap(temball);

        }
        else
        {
            Robot_team[order-5].player_image=role_image;
            //创建临时球员窗口
            QWidget cur_player(this);
            cur_player.setGeometry( Robot_team[order-5].Widget_width, Robot_team[order-5].Widget_height, Robot_team[order-5].Player_location_x, Robot_team[order-5].Player_label_location_y);
            //创建临时球员label
            QLabel player_label(&cur_player);
            player_label.setGeometry( Robot_team[order-5].Player_label_width, Robot_team[order-5].Player_label_height, Robot_team[order-5].Player_label_location_x, Robot_team[order-5].Player_label_location_y);
            player_label.setPixmap( Robot_team[order-5].player_image);
            //创建临时球label
            QLabel ball_label(&cur_player);
            ball_label.setGeometry( Robot_team[order-5].Ball_label_width, Robot_team[order-5].Ball_label_height, Robot_team[order-5].Ball_label_location_x, Robot_team[order-5].Ball_label_location_y);
            ball_label.setPixmap(temball);
        }
    });

    //连接background替换信号与对应槽函数，完成界面背景的设置替换
    BackGround_Seetings* set_background=new BackGround_Seetings;
    connect(set_background,&BackGround_Seetings::sendSignal_background,this,[=](QPixmap background){
        gamepanel->Gamepanel_label->setPixmap(background);
    });

}

GamePanel::~GamePanel()
{
    delete gamepanel;
}


//弹出帮助窗口函数
void GamePanel::Helper()
{
    HelperPanel* helperpanel=new HelperPanel;
    helperpanel->show();
}

//弹出音量设置窗口函数
void GamePanel::voiceForce()
{
    VoiceSettings* setVoice=new VoiceSettings;
    setVoice->show();
}


//弹出球员设置窗口函数
void GamePanel::Replace()
{
    RoleSettings* setRole=new RoleSettings;
    setRole->show();
}

//弹出背景设置窗口函数
void GamePanel::backGroundSeetings()
{
    BackGround_Seetings* setGamePanel_background=new BackGround_Seetings;
    setGamePanel_background->show();
}

//重写keyPressEvent按键处理函数
void GamePanel::keyPressEvent(QKeyEvent* cur_key)
{
    emit sendSignal_keyevent(cur_key);
}
