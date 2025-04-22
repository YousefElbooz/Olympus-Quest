QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Gym_classes.cpp \
    Member.cpp \
    coach.cpp \
    filehandler.cpp \
    main.cpp \
    main_alaa.cpp \
    mainwindow.cpp \
    manager.cpp \
    receptionist.cpp \
    staff.cpp

HEADERS += \
    Gym_classes.h \
    Member.h \
    coach.h \
    filehandler.h \
    mainwindow.h \
    manager.h \
    receptionist.h \
    staff.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Staff.txt \
    classes.txt \
    coach.txt \
    enrollments.txt \
    users.txt
