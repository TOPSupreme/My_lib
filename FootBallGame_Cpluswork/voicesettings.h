
#ifndef VOICESETTINGS_H
#define VOICESETTINGS_H


#include <QWidget>

namespace Ui{
class VoiceSettings_panel;
}

class VoiceSettings : public QWidget
{
    Q_OBJECT
public:
    explicit VoiceSettings(QWidget *parent = nullptr);
    ~VoiceSettings();
private:
    Ui::VoiceSettings_panel* voiceSettings;
signals:

public slots:
    void PressOK();
};

#endif // VOICESETTINGS_H
