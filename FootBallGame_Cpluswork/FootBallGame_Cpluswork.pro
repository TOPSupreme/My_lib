QT       += core gui
QT       += core gui sql
QT       += sql
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background_seetings.cpp \
    error.cpp \
    failure.cpp \
    gamemainmenu.cpp \
    gamemainmenu_settings.cpp \
    gamepanel.cpp \
    headimage_settings.cpp \
    helperpanel.cpp \
    isexit_dialog.cpp \
    keypressevent_thread.cpp \
    login.cpp \
    main.cpp \
    noncontrolplayers_thread.cpp \
    nongoalkeeper_thread.cpp \
    player.cpp \
    registerpanel.cpp \
    resetpasswordpanel.cpp \
    rolesettings.cpp \
    tie.cpp \
    timepanel_thread.cpp \
    victory.cpp \
    voicesettings.cpp \
    mywindow.cpp

HEADERS += \
    background_seetings.h \
    error.h \
    failure.h \
    gamemainmenu.h \
    gamemainmenu_settings.h \
    gamepanel.h \
    headimage_settings.h \
    helperpanel.h \
    isexit_dialog.h \
    keypressevent_thread.h \
    login.h \
    noncontrolplayers_thread.h \
    nongoalkeeper_thread.h \
    player.h \
    registerpanel.h \
    resetpasswordpanel.h \
    rolesettings.h \
    tie.h \
    timepanel_thread.h \
    victory.h \
    voicesettings.h

FORMS += \
    background_settings.ui \
    error.ui \
    failure.ui \
    gamemainmenu.ui \
    gamemainmenu_settings.ui \
    gamepanel.ui \
    headimage_settings.ui \
    helperpanel.ui \
    isexit_dialog.ui \
    login.ui \
    registerpanel.ui \
    resetpasswordpanel.ui \
    rolesettings.ui \
    tie.ui \
    victory.ui \
    voicesettings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources_file.qrc

DISTFILES +=
