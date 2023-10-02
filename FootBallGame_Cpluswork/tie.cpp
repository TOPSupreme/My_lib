
#include "tie.h"
#include "ui_tie.h"

Tie::Tie(QWidget *parent)
    : QWidget{parent},
    tie_panel(new Ui::TiePanel)
{
    tie_panel->setupUi(this);
    //设置面板背景
    QPixmap tie_background(":/game_resources/Tie(1).jpg");
    tie_panel->tie_panel_background->setPixmap(tie_background);
}

Tie::~Tie()
{
    delete tie_panel;
}
