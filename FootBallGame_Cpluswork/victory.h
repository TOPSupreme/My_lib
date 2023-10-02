
#ifndef VICTORY_H
#define VICTORY_H


#include <QWidget>

namespace Ui{
class VictoryPanel;
}

class Victory : public QWidget
{
    Q_OBJECT
public:
    explicit Victory(QWidget *parent = nullptr);
    ~Victory();
    Ui::VictoryPanel* victor_panel;
signals:

};

#endif // VICTORY_H
