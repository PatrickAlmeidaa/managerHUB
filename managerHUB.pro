QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agendamento_horarios.cpp \
    gerent.cpp \
    login_tela.cpp \
    main.cpp \
    marcar_horario.cpp

HEADERS += \
    agendamento_horarios.h \
    gerent.h \
    login_tela.h \
    marcar_horario.h

FORMS += \
    gerent.ui \
    login_tela.ui \
    marcar_horario.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
