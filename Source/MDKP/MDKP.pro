QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    adminwindowdeluser.cpp \
    main.cpp \
    authorization.cpp \
    useractivedeliverywindow.cpp \
    userorderlistwindow.cpp \
    workeractivedelivery.cpp \
    workeradddelivery.cpp \
    workereditdelivery.cpp

HEADERS += \
    adminwindow.h \
    adminwindowdeluser.h \
    authorization.h \
    useractivedeliverywindow.h \
    userorderlistwindow.h \
    workeractivedelivery.h \
    workeradddelivery.h \
    workereditdelivery.h

FORMS += \
    adminwindow.ui \
    adminwindowdeluser.ui \
    authorization.ui \
    useractivedeliverywindow.ui \
    userorderlistwindow.ui \
    workeractivedelivery.ui \
    workeradddelivery.ui \
    workereditdelivery.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
