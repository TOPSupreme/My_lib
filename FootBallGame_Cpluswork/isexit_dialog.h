
#ifndef ISEXIT_DIALOG_H
#define ISEXIT_DIALOG_H


#include <QWidget>

namespace Ui{
class IsExit_dialog_panel;
}

class IsExit_dialog : public QWidget
{
    Q_OBJECT
public:
    explicit IsExit_dialog(QWidget *parent = nullptr);
    ~IsExit_dialog();
private:
    Ui::IsExit_dialog_panel* isExit_panel;
signals:

};

#endif // ISEXIT_DIALOG_H
