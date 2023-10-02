
#ifndef BUTTONSETTINGS_H
#define BUTTONSETTINGS_H


#include <QWidget>

namespace Ui{
class ButtonSettings_panel;
}

class ButtonSettings : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonSettings(QWidget *parent = nullptr);
    ~ButtonSettings();
private:
    Ui::ButtonSettings_panel* buttonSettings;

signals:

};

#endif // BUTTONSETTINGS_H
