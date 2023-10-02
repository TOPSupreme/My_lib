
#include"login.h"
#include <QApplication>
#include<QDebug>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <gamemainmenu_settings.h>



//测试数据库连接函数 连接成功 返回true 连接失败 返回false
bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("footballgame_database");
    db.setUserName("root");
    db.setPassword("20040904hyh");
    bool ok = db.open();
    if (ok)
    {
        qDebug() << "连接成功" ;
        return true;
    }
    else
    {
        qDebug() << "连接失败" ;
        return false;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection())
        return 1;
    Login s;
    s.show();



    return a.exec();
}
