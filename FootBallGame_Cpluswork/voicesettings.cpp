
#include "voicesettings.h"
#include "ui_voicesettings.h"
#include <QPixmap>
#include <QMediaPlayer>

VoiceSettings::VoiceSettings(QWidget *parent)
    : QWidget{parent},
    voiceSettings(new Ui::VoiceSettings_panel)
{
    voiceSettings->setupUi(this);
    QPixmap voiceSetting_background(":/game_resources/voiceforce_settings_background.png");
    voiceSettings->VoiceSetting_panel_background->setPixmap(voiceSetting_background);
    //连接OK button与PressOk()函数，完成相应点击响应
    connect(voiceSettings->OK_pushbutton,&QPushButton::clicked,this,&VoiceSettings::PressOK);

}

VoiceSettings::~VoiceSettings()
{
    delete voiceSettings;
}

void VoiceSettings::PressOK()
{
    //重新设置背景音乐音量并播放
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(":/game_resources/gamebgm.mp3"));
    player->setVolume(voiceSettings->Voiceforce_number->text().toInt());
    player->play();
}
