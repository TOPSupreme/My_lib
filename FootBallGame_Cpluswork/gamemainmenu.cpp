#include "gamemainmenu.h"
#include "ui_gamemainmenu.h"
#include "gamepanel.h"
#include "isexit_dialog.h"
#include "helperpanel.h"
#include <QPixmap>
#include  <QDebug>
#include <QPushButton>
#include "gamemainmenu_settings.h"
#include <QMediaPlayer>

GameMainmenu::GameMainmenu(QWidget *parent)
    : QWidget{parent},
    mainmenu(new Ui::GameMainmenu)
{
    mainmenu->setupUi(this);
    QPixmap mainmenu_background(":/game_resources/game_ui_image2(1)");
    mainmenu->background_label->setPixmap(mainmenu_background);
    connect(mainmenu->Start_pushbutton,&QPushButton::clicked,this,&GameMainmenu::Start);
    connect(mainmenu->Exit_pushbutton,&QPushButton::clicked,this,&GameMainmenu::Exit);
    connect(mainmenu->Settings_pushbutton,&QPushButton::clicked,this,&GameMainmenu::Settings);
    connect(mainmenu->Helper_pushbutton,&QPushButton::clicked,this,&GameMainmenu::Helper);
    //关联背景音乐播放与GameMainmenu的OPEN函数，以及close函数
    //实现打开游戏自动播放背景音乐，关闭游戏自动停止播放
    //初始化背景音乐的音量为50
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("gamebgm.mp3"));
    player->setVolume(50);
    player->play();
}

GameMainmenu::~GameMainmenu()
{
    delete mainmenu;
}

void GameMainmenu::Start()
{
    //定义GamePanel对象，并调用其show函数显示主游戏窗口
    GamePanel *panel=new GamePanel;
    panel->show();
    emit sendSignal_Triggered(true);
}

void GameMainmenu::Exit()
{
    //定义IsExit_dialog对象，并调用其show函数显示IsExit_dialog对话框
    IsExit_dialog *exit=new IsExit_dialog;
    exit->show();

}

void GameMainmenu::Settings()
{
    //定义MainMenu的Settings对象，并调用其show函数显示MainMenu_Settings窗口
    GameMainMenu_Settings *panel=new GameMainMenu_Settings;
    panel->show();
}

void GameMainmenu::Helper()
{
    //定义HelperPanel对象，并调用其show函数显示帮助窗口
    HelperPanel *panel=new HelperPanel;
    panel->show();

}
