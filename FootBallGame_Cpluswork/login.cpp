
#include "login.h"
#include "ui_login.h"
#include<QPixmap>
#include<QDebug>
#include<QPushButton>
#include"gamemainmenu.h"
#include "resetpasswordpanel.h"
#include"registerpanel.h"
#include "resetpasswordpanel.h"
#include "error.h"
#include <QSqlDatabase>
#include <QSqlQuery>

Login::Login(QWidget *parent)
    : QWidget{parent},
    log(new Ui::GameLoginWidget)
{
    log->setupUi(this);
    QPixmap login_background(":/game_resources/game_ui_image1(2).jpg");
    log->label->setPixmap(login_background);
    connect(log->Login_button,&QPushButton::clicked,this,&Login::LoginGame);
    connect(log->Forgot_button,&QPushButton::clicked,this,&Login::ForgetPassword);
    connect(log->Register_button,&QPushButton::clicked,this,&Login::Register);

}

Login::~Login()
{
    delete log;
}

void Login::LoginGame()
{
    QSqlQuery query;
    query.bindValue(":name",log->UserName->text());
    query.bindValue(":password",log->Password->text());
    if (query.exec("SELECT * FROM mytable WHERE UserName= :name,PassWord=:password")) {
        GameMainmenu *gameMainmenu=new GameMainmenu;
        gameMainmenu->show();
        qDebug()<<"查询成功";
    } else {
        //所输密码与用户名不正确，则显示错误窗口
        Error* mistake=new Error;
        mistake->show();
        qDebug()<<"查询失败";
    }
}

void  Login::ForgetPassword()
{
    ResetPasswordPanel* resetPassword=new ResetPasswordPanel;
    resetPassword->show();

}

void Login::Register()
{
    //定义RegisterPanel对象，并调用其show函数完成注册窗口显示
    RegisterPanel* reGister=new RegisterPanel;
    reGister->show();
}
