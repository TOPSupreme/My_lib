
#include "background_seetings.h"
#include "ui_background_settings.h"
#include "QPixmap"

BackGround_Seetings::BackGround_Seetings(QWidget *parent)
    : QWidget{parent},
    GamePanel_background(new Ui::BackGround_Settings_Panel)

{
    GamePanel_background->setupUi(this);
    //设置面板背景
    QPixmap panel_background(":/game_resources/background_settings_background(1).jpg");
    GamePanel_background->PanelBackground->setPixmap(panel_background);
    //设置相关选项背景图片
    QPixmap bcg1(":/game_resources/football_Field_image2(2)(1).jpg");
    QPixmap bcg2(":/game_resources/football_Field_image2(3)(1).jpg");
    QPixmap bcg3(":/game_resources/football_Field_image2(4)(1).jpg");
    GamePanel_background->background1->setPixmap(bcg1);
    GamePanel_background->background2->setPixmap(bcg2);
    GamePanel_background->background3->setPixmap(bcg3);
    //连接OK键以及对应的槽函数PressOk
    connect(GamePanel_background->OK_pushbutton,&QPushButton::clicked,this,&BackGround_Seetings::PressOK);
    //背景设置Stacked widget窗口还需改进，参见headimage_settings换用多线程

}

BackGround_Seetings::~BackGround_Seetings()
{
    delete GamePanel_background;
}

//实现PressOk函数，定义点击事件发生后将要完成的操作
void BackGround_Seetings::PressOK()
{
    int curIndex=GamePanel_background->Backgrounds->currentIndex();
    if(curIndex==1)
    {
        QPixmap chosen_background(":/game_resources/football_Field_image2(2)(1).jpg");
        emit sendSignal_background(chosen_background);
        this->close();
        return ;
    }

    else if(curIndex==2)
    {
        QPixmap chosen_background(":/game_resources/football_Field_image2(3)(1).jpg");
        emit sendSignal_background(chosen_background);
        this->close();
        return ;
    }

    else
    {
        QPixmap chosen_background(":/game_resources/football_Field_image2(4)(1).jpg");
        emit sendSignal_background(chosen_background);
        this->close();
        return ;
    }
}
