QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Gym_classes.cpp \
    Manager.cpp \
    Member.cpp \
    filehandler.cpp \
    main.cpp \
    main_alaa.cpp \
    mainwindow.cpp

HEADERS += \
    Gym_classes.h \
    Manager.h \
    Member.h \
    filehandler.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    classes.txt \
    enrollments.txt \
    members.txt \
    temp.txt \
    users.txt
