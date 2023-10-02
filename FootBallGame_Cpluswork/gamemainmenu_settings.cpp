
#include "gamemainmenu_settings.h"
#include "ui_gamemainmenu_settings.h"
#include "voicesettings.h"
#include "background_seetings.h"
#include "rolesettings.h"
#include "headimage_settings.h"
#include "QPixmap"

GameMainMenu_Settings::GameMainMenu_Settings(QWidget *parent)
    : QWidget{parent},
    settings(new Ui::Settings_panel)
{
    settings->setupUi(this);
    //设置Settings面板的背景图
    QPixmap settings_panel_background(":/game_resources/Settings_panel_background(1).jpg");
    settings->SettingsPanel_background_label->setPixmap(settings_panel_background);
    //将功能按钮与对应槽函数连接
    connect(settings->VoiceSetting_pushbutton,&QPushButton::clicked,this,&GameMainMenu_Settings::Voiceforce_settings);
    connect(settings->BackgroundSetting_pushbutton,&QPushButton::clicked,this,&GameMainMenu_Settings::Background_settings);
    connect(settings->RoleSetting_pushbutton,&QPushButton::clicked,this,&GameMainMenu_Settings::Role_settings);
    connect(settings->HeadimageSetting_pushbutton,&QPushButton::clicked,this,&GameMainMenu_Settings::Headimage_settings);
}

//析构函数
GameMainMenu_Settings::~GameMainMenu_Settings()
{
    delete settings;
}

//显示音量设置窗口
void GameMainMenu_Settings::Voiceforce_settings()
{
    VoiceSettings* setVoice=new VoiceSettings;
    setVoice->show();
}



//显示背景设置窗口
void GameMainMenu_Settings::Background_settings()
{
    BackGround_Seetings* setBackground=new BackGround_Seetings;
    setBackground->show();
}

//显示角色设置窗口
void GameMainMenu_Settings::Role_settings()
{
    RoleSettings* setRole=new RoleSettings;
    setRole->show();
}

//显示头像设置窗口
void GameMainMenu_Settings::Headimage_settings()
{
    HeadImage_Settings* setHeadimage=new HeadImage_Settings;
    setHeadimage->show();
}

