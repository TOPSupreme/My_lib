
#include "victory.h"
#include "ui_victory.h"

Victory::Victory(QWidget *parent)
    : QWidget{parent},
    victor_panel(new Ui::VictoryPanel)
{
    victor_panel->setupUi(this);
    //设置面板背景
    QPixmap victor_background(":/game_resources/victory(1).jpg");
    victor_panel->victory_panel_baackground->setPixmap(victor_background);

}

Victory::~Victory()
{
    delete victor_panel;
}
