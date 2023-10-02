
#include "rolesettings.h"
#include "ui_rolesettings.h"
#include "QPixmap"

RoleSettings::RoleSettings(QWidget *parent)
    : QWidget{parent},
    roleSettings(new Ui::RoleSettings_panel)
{
    roleSettings->setupUi(this);
    //设置角色设置面板背景
    QPixmap background(":/game_resources/rolesettings_background(1).jpg");
    roleSettings->RoleSettings_panel_background->setPixmap(background);
    //设置角色选择框角色图片
    QPixmap role1(":/game_resources/player1_Cristiano(1).jpg");
    QPixmap role2(":/game_resources/player2_Messi(1).jpg");
    QPixmap role3(":/game_resources/player3_Mbappe(1).jpg");
    QPixmap role4(":/game_resources/player4_Harland(1).png");
    QPixmap role5(":/game_resources/player5_Levan(1).jpg");
    QPixmap role6(":/game_resources/player6_Neymar(1).png");
    QPixmap role7(":/game_resources/player7_Lbrahimovic(1).png");
    QPixmap role8(":/game_resources/player8_LukaModidric(1).png");
    QPixmap role9(":/game_resources/player9_Suarez(1).jpg");
    QPixmap role10(":/game_resources/player10_Venus(1).png");
    QPixmap role11(":/game_resources/player11_Maradona(1).png");
    QPixmap role12(":/game_resources/player12_Benzema(1).png");
    QPixmap role13(":/game_resources/player13_Felix(1).png");
    QPixmap role14(":/game_resources/player1_Courtois(1).png");
    QPixmap role15(":/game_resources/player1_Martinnez(1).png");
    roleSettings->player1->setPixmap(role1);
    roleSettings->player2->setPixmap(role2);
    roleSettings->player3->setPixmap(role3);
    roleSettings->player4->setPixmap(role4);
    roleSettings->player5->setPixmap(role5);
    roleSettings->player6->setPixmap(role6);
    roleSettings->player7->setPixmap(role7);
    roleSettings->player8->setPixmap(role8);
    roleSettings->player9->setPixmap(role9);
    roleSettings->player10->setPixmap(role10);
    roleSettings->player11->setPixmap(role11);
    roleSettings->player12->setPixmap(role12);
    roleSettings->player13->setPixmap(role13);
    roleSettings->player14->setPixmap(role14);
    roleSettings->player15->setPixmap(role15);

    //连接OK按钮与PressOK函数，完成信号与槽连接，完成点击响应
    connect(roleSettings->OK_pushbutton,&QPushButton::clicked,this,&RoleSettings::PressOK);

    //角色设置Stacked widget窗口还需改进，参见headimage_settings换用多线程

}


RoleSettings::~RoleSettings()
{
    delete roleSettings;
}

//实现PressOK函数
void RoleSettings::PressOK()
{
    //根据cureentIndex函数优先判断所选号位，再根据索引更换对应球员
    //1-5 MyP1-MyP5 1-6 Robot_P1-Robot_P5
    int curIndex=roleSettings->PlayerOrders->currentIndex();
    if(curIndex==1)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==2)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==3)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==4)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==5)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==6)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
             emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==7)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
             emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==8)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
             emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==9)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }

    if(curIndex==10)
    {
        int cur_Index=roleSettings->Players->currentIndex();
        if(cur_Index==1)
        {
            QPixmap Role(":/game_resources/gameplayer_image1_Cristiano(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==2)
        {
            QPixmap Role(":/game_resources/gameplayer_image2_Messi(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==3)
        {
            QPixmap Role(":/game_resources/gameplayer_image7_Mbappe(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==4)
        {
            QPixmap Role(":/game_resources/gameplayer_image8_Harland(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==5)
        {
            QPixmap Role(":/game_resources/gameplayer_image15_Levan(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==6)
        {
            QPixmap Role(":/game_resources/gameplayer_image6_Neymar(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==7)
        {
            QPixmap Role(":/game_resources/gameplayer_image9_Lbrahimovic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==8)
        {
            QPixmap Role(":/game_resources/gameplayer_image10_Lukamodvic(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==9)
        {
            QPixmap Role(":/game_resources/gameplayer_image3_Suarez(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==10)
        {
            QPixmap Role(":/game_resources/gameplayer_image13_Venus(1).png");
            emit sendSignal(Role,curIndex);
        }
        if(cur_Index==11)
        {
            QPixmap Role(":/game_resources/gameplayer_image4_Maradona(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==12)
        {
            QPixmap Role(":/game_resources/gameplayer_image11_Benzema(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==13)
        {
            QPixmap Role(":/game_resources/gameplayer_image5_Flix(1).png");
            emit sendSignal(Role,curIndex);
        }
        else if(cur_Index==14)
        {
            QPixmap Role(":/game_resources/gameplayer_image14_Courtois(1).png");
            emit sendSignal(Role,curIndex);
        }
        else
        {
            QPixmap Role(":/game_resources/gameplayer_image12_Matinnez(1).png");
            emit sendSignal(Role,curIndex);
        }
    }
}
