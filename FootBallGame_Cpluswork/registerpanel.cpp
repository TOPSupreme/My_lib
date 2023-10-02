
#include "registerpanel.h"
#include"ui_registerpanel.h"
#include <QPixmap>
#include "error.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

RegisterPanel::RegisterPanel(QWidget *parent)
    : QWidget{parent},
    regis(new Ui::RegisterPanel)

{
    regis->setupUi(this);
    QPixmap Regisbackground(":/game_resources/registerpanel_background(1).png");
    regis->RegisterPanel_background->setPixmap(Regisbackground);
    //连接rgister键与PressOk()函数完成信号与槽连接，完成相关响应
    connect(regis->Register_pushbutton,&QPushButton::clicked,this,&RegisterPanel::PressRegister);

}

RegisterPanel::~RegisterPanel()
{
    delete regis;
}

void RegisterPanel::PressRegister()
{
    QSqlQuery query;
    //如果用户所输入数据符合要求，则将数据录入数据库中
    if(regis->Confirm_edit->text()==regis->Password_edit->text())
    {
    query.prepare("INSERT INTO usersdata (UsersName, PassWord)VALUES (:UsersName, :PassWord)");
    query.bindValue(":UsersName",regis->UserName_edit->text());
    query.bindValue(":PassWord", regis->Password_edit->text());
    if(!query.exec())
    {
        qDebug() << "Failed to insert data!";
    }
    else
    {
        qDebug() << "Data inserted successfully!";
    }
    this->close();

    }
    //否则，显示错误面板
    else
    {
       Error *error=new Error;
       error->show();
    }

}


