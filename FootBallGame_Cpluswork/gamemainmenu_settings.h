
#ifndef GAMEMAINMENU_SETTINGS_H
#define GAMEMAINMENU_SETTINGS_H


#include <QWidget>

namespace Ui{
class Settings_panel;
}

class GameMainMenu_Settings : public QWidget
{
    Q_OBJECT
public:
    explicit GameMainMenu_Settings(QWidget *parent = nullptr);
    ~GameMainMenu_Settings();
private:
    Ui::Settings_panel* settings;
signals:


public slots:
    void Voiceforce_settings();
    void Background_settings();
    void Role_settings();
    void Headimage_settings();

};

#endif // GAMEMAINMENU_SETTINGS_H
