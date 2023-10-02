
#include "failure.h"
#include "ui_failure.h"

Failure::Failure(QWidget *parent)
    : QWidget{parent},
    failpanel(new Ui::FailurePanel)
{
    failpanel->setupUi(this);
    //设置背景板
    QPixmap fail_background(":/game_resources/failure(1).jpg");
    failpanel->failure_panel_background->setPixmap(fail_background);
}

Failure::~Failure()
{
    delete failpanel;
}

