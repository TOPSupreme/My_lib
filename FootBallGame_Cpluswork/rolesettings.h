
#ifndef ROLESETTINGS_H
#define ROLESETTINGS_H


#include <QWidget>
#include <QPixmap>

namespace Ui{
class RoleSettings_panel;
}

class RoleSettings : public QWidget
{
    Q_OBJECT
public:
    explicit RoleSettings(QWidget *parent = nullptr);
    ~RoleSettings();
private:
    Ui::RoleSettings_panel* roleSettings;

signals:
    void sendSignal(QPixmap role_image,int Order);

public slots:
    void PressOK();
};

#endif // ROLESETTINGS_H
