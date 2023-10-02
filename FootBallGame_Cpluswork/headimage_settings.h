
#ifndef HEADIMAGE_SETTINGS_H
#define HEADIMAGE_SETTINGS_H


#include <QWidget>

namespace Ui{
class HeadImage_Settings_panel;
}

class HeadImage_Settings : public QWidget
{
    Q_OBJECT
public:
    explicit HeadImage_Settings(QWidget *parent = nullptr);
    ~HeadImage_Settings();

private:
    Ui::HeadImage_Settings_panel* headimage_Settings;
public slots:
    void PressOK();
    void nextHeadimage();

signals:
    void sendSignal(QPixmap headimage);

};

#endif // HEADIMAGE_SETTINGS_H
