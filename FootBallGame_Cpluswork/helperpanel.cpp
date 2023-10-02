
#include "helperpanel.h"
#include"ui_helperpanel.h"

HelperPanel::HelperPanel(QWidget *parent)
    : QWidget{parent},
    helper(new Ui::HelperPanel)
{
    helper->setupUi(this);
}

HelperPanel::~HelperPanel()
{
    delete helper;
}

