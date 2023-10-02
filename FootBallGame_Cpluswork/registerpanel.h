
#ifndef REGISTERPANEL_H
#define REGISTERPANEL_H


#include <QWidget>

namespace Ui{
class RegisterPanel;
}

class RegisterPanel : public QWidget
{
    Q_OBJECT
public:
    explicit RegisterPanel(QWidget *parent = nullptr);
    ~RegisterPanel();
private:
    Ui::RegisterPanel* regis;
signals:

public slots:
    void PressRegister();

};

#endif // REGISTERPANEL_H
