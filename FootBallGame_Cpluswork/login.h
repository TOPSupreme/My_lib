
#ifndef LOGIN_H
#define LOGIN_H


#include <QWidget>

namespace Ui{
class GameLoginWidget;
}


class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    Ui::GameLoginWidget * log;


public slots:
    void LoginGame();
    void ForgetPassword();
    void Register();


};

#endif // LOGIN_H
