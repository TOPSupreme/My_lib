
#include "resetpasswordpanel.h"
#include"ui_resetpasswordpanel.h"
#include <QPixmap>
#include "error.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "login.h"
#include "ui_login.h"
#include <QDebug>

ResetPasswordPanel::ResetPasswordPanel(QWidget *parent)
    : QWidget{parent},
    resetpassword(new Ui::ResetPasswordPanel)
{
    resetpassword->setupUi(this);
    QPixmap Reset_panel_background(":/game_resources/resetpassword_panel_background(1).jpg");
    resetpassword->ResetPanel_background->setPixmap(Reset_panel_background);
    //连接相关信号与槽函数，reset与Pressreset()函数，完成相关响应
    connect(resetpassword->Reset_pushbutton,&QPushButton::clicked,this,&ResetPasswordPanel::Pressreset);

}

ResetPasswordPanel::~ResetPasswordPanel()
{
    delete resetpassword;
}

void ResetPasswordPanel::Pressreset()
{
    QSqlQuery query;
    //如果用户所输入数据符合要求，则将数据录入数据库中
    if(resetpassword->Confirm_edit->text()==resetpassword->Newpassword_edit->text())
    {
        Login login;
        query.prepare("UPDATE usersdata SET Password=:password where UsersName=:name");
        query.bindValue(":password",resetpassword->Confirm_edit->text() );
        query.bindValue(":name", login.log->UserName->text());
        qDebug()<<"设置成功";
    }
    //否则，显示错误面板
    else
    {
        Error* error=new Error;
        error->show();
        qDebug()<<"设置失败";
    }

}

