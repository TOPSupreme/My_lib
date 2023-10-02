
#ifndef TIE_H
#define TIE_H


#include <QWidget>

namespace Ui{
class TiePanel;
}

class Tie : public QWidget
{
    Q_OBJECT
public:
    explicit Tie(QWidget *parent = nullptr);
    ~Tie();
    Ui::TiePanel* tie_panel;

signals:

};

#endif // TIE_H
