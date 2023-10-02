
#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include <QString>


//本游戏中，为了实现的简便，场上的球员由一个窗口构成，窗口中包含了两个label
//分别用于存储对应球员的Image图像，以及足球的Image图像
//其中球员窗口大小，以及两个label的大小和在球员窗口中的位置固定
//将在构造函数中进行实现
class Player
{
public:
    Player();
    ~Player();
    //两个Pixmap对象分别用于存储球员与足球的图像
    QPixmap player_image;
    QPixmap football_image;
    //定义int型变量，存储窗口的大小，label的大小，以及各部件的位置
    int Widget_width;
    int Widget_height;
    int Ball_label_width;
    int Ball_label_height;
    int Player_label_width;
    int Player_label_height;
    int Player_location_x;
    int Player_location_y;
    int Player_label_location_x;
    int Player_label_location_y;
    int Ball_label_location_x;
    int Ball_label_location_y;
    //判断当前球员是否为玩家当前所操控球员
    QString status;
};

#endif // PLAYER_H
