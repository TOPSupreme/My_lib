
#ifndef GAMEMAINMENU_H
#define GAMEMAINMENU_H


#include <QWidget>

namespace Ui{
class GameMainmenu;
}

class GameMainmenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameMainmenu(QWidget *parent = nullptr);
    ~GameMainmenu();
private:
    Ui::GameMainmenu* mainmenu;
signals:
    void sendSignal_Triggered(bool trigger);

public slots:
    void Start();
    void Exit();
    void Settings();
    void Helper();

};

#endif // GAMEMAINMENU_H
