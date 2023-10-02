
#ifndef HELPERPANEL_H
#define HELPERPANEL_H


#include <QWidget>

namespace Ui{
class  HelperPanel;
}

class HelperPanel : public QWidget
{
    Q_OBJECT
public:
    explicit HelperPanel(QWidget *parent = nullptr);
    ~HelperPanel();
private:
    Ui::HelperPanel * helper;
signals:

};

#endif // HELPERPANEL_H
