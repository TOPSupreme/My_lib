
#ifndef REPLACEPLAYER_H
#define REPLACEPLAYER_H


#include <QWidget>

namespace Ui{
class ReplacePlayer;
}
class ReplacePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit ReplacePlayer(QWidget *parent = nullptr);
    ~ReplacePlayer();
private:
    Ui::ReplacePlayer* replace;

signals:

};

#endif // REPLACEPLAYER_H
