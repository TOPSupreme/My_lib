
#include "replaceplayer.h"
#include "ui_replaceplayer.h"

ReplacePlayer::ReplacePlayer(QWidget *parent)
    : QWidget{parent},
    replace(new Ui::ReplacePlayer)
{
    replace->setupUi(this);
}

ReplacePlayer::~ReplacePlayer()
{
    delete replace;
}
