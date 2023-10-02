
#include "isexit_dialog.h"
#include "ui_isexit_dialog.h"

IsExit_dialog::IsExit_dialog(QWidget *parent)
    : QWidget{parent},
    isExit_panel(new Ui::IsExit_dialog_panel)
{
    isExit_panel->setupUi(this);
    QPixmap background(":/game_resources/voiceforce_settingd_background.png");
    isExit_panel->label->setPixmap(background);
}

IsExit_dialog::~IsExit_dialog()
{
    delete isExit_panel;
}
