
#include "headimage_settings.h"
#include "ui_headimage_settings.h"
#include <QPushButton>

HeadImage_Settings::HeadImage_Settings(QWidget *parent)
    : QWidget{parent},
    headimage_Settings(new Ui::HeadImage_Settings_panel)
{
    headimage_Settings->setupUi(this);
    //设置面板背景
    QPixmap panel_background(":/game_resources/headimage_settings_background(1).jpg");
    headimage_Settings->headimage_settings_background->setPixmap(panel_background);
    //设置相关选项图片
    QPixmap headimg1(":/game_resources/headimage1(1).png");
    QPixmap headimg2(":/game_resources/headimage2(1).png");
    QPixmap headimg3(":/game_resources/headimage3(1).png");
    QPixmap headimg4(":/game_resources/headimage4(1).png");
    QPixmap headimg5(":/game_resources/headimage5(1).png");
    QPixmap headimg6(":/game_resources/headimage6(1).png");
    QPixmap headimg7(":/game_resources/headimage7(1).png");
    headimage_Settings->headimage1->setPixmap(headimg1);
    headimage_Settings->headimage2->setPixmap(headimg2);
    headimage_Settings->headimage3->setPixmap(headimg3);
    headimage_Settings->headimage4->setPixmap(headimg4);
    headimage_Settings->headimage5->setPixmap(headimg5);
    headimage_Settings->headimage6->setPixmap(headimg6);
    headimage_Settings->headimage7->setPixmap(headimg7);

    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget1);
    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget2);
    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget3);
    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget4);
    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget5);
    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget6);
    headimage_Settings->Headimages->addWidget(headimage_Settings->image_widget7);
    //设置当前窗口初始默认窗口界面
    headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget1);
    //连接OK键以及对应的槽函数PressOk
    connect(headimage_Settings->OK_pushbutton,&QPushButton::clicked,this,&HeadImage_Settings::PressOK);
    //连接NEXT pushbutton按钮与切换图像槽函数
    connect(headimage_Settings->next_pushbutton,&QPushButton::clicked,this,&HeadImage_Settings::nextHeadimage);

}

HeadImage_Settings::~HeadImage_Settings()
{
    delete headimage_Settings;
}

//实现PressOk函数，定义点击事件发生后将要完成的操作
void HeadImage_Settings::PressOK()
{
    int curIndex=headimage_Settings->Headimages->currentIndex();
    if(curIndex==1)
    {
        QPixmap chosen_headimage(":/game_resources/headimage1(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }

    else if(curIndex==2)
    {
        QPixmap chosen_headimage(":/game_resources/headimage2(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }

    else if(curIndex==3)
    {
        QPixmap chosen_headimage(":/game_resources/headimage3(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }

    else if(curIndex==4)
    {
        QPixmap chosen_headimage(":/game_resources/headimage4(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }

    else if(curIndex==5)
    {
        QPixmap chosen_headimage(":/game_resources/headimage5(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }

    else if(curIndex==6)
    {
        QPixmap chosen_headimage(":/game_resources/headimage6(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }

    if(curIndex==7)
    {
        QPixmap chosen_headimage(":/game_resources/headimage7(1).png");
        emit sendSignal(chosen_headimage);
        this->close();
        return ;
    }
}

//还需改进，换用多线程
void HeadImage_Settings::nextHeadimage()
{
    int curIndex=headimage_Settings->Headimages->currentIndex();
    if(curIndex==1)
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget2);
    else if(curIndex==2)
    {
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget3);
    }
    else if(curIndex==3)
    {
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget4);
    }
    else if(curIndex==4)
    {
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget5);
    }
    else if(curIndex==5)
    {
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget6);
    }
    else if(curIndex==6)
    {
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget7);
    }
    else
        headimage_Settings->Headimages->setCurrentWidget(headimage_Settings->image_widget1);
}
