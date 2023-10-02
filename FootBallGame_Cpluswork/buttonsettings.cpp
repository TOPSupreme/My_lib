
#include "buttonsettings.h"
#include "ui_buttonsettings.h"

ButtonSettings::ButtonSettings(QWidget *parent)
    : QWidget{parent},
    buttonSettings(new Ui::ButtonSettings_panel)
{
    buttonSettings->setupUi(this);
}

ButtonSettings::~ButtonSettings()
{
    delete buttonSettings;
}
