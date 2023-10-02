
#ifndef BACKGROUND_SEETINGS_H
#define BACKGROUND_SEETINGS_H


#include <QWidget>
#include <QPixmap>

namespace Ui{
class BackGround_Settings_Panel;
}

class BackGround_Seetings : public QWidget
{
    Q_OBJECT
public:
    explicit BackGround_Seetings(QWidget *parent = nullptr);
    ~BackGround_Seetings();
private:
    Ui::BackGround_Settings_Panel* GamePanel_background;

signals:
    void sendSignal_background(QPixmap background);

public slots:
    void PressOK();
};

#endif // BACKGROUND_SEETINGS_H
