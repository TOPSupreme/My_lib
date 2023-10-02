
#ifndef RESETPASSWORDPANEL_H
#define RESETPASSWORDPANEL_H


#include <QWidget>

namespace Ui{
class ResetPasswordPanel;
}

class ResetPasswordPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ResetPasswordPanel(QWidget *parent = nullptr);
    ~ResetPasswordPanel();
private:
    Ui::ResetPasswordPanel* resetpassword;

signals:

public slots:
    void Pressreset();

};

#endif // RESETPASSWORDPANEL_H
