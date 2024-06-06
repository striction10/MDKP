QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    adminwindowdeluser.cpp \
    database.cpp \
    deliveryalluser.cpp \
    deliveryallusersmodel.cpp \
    deliverymodeluser.cpp \
    deliveryuser.cpp \
    main.cpp \
    authorization.cpp \
    makeorder.cpp \
    product.cpp \
    productmodel.cpp \
    user.cpp \
    useractivedeliverywindow.cpp \
    userorderlistwindow.cpp \
    usersmodel.cpp \
    workeractivedelivery.cpp \
    workeradddelivery.cpp \
    workereditdelivery.cpp \
    workereditproduct.cpp

HEADERS += \
    adminwindow.h \
    adminwindowdeluser.h \
    authorization.h \
    database.h \
    deliveryalluser.h \
    deliveryallusersmodel.h \
    deliverymodeluser.h \
    deliveryuser.h \
    makeorder.h \
    product.h \
    productmodel.h \
    user.h \
    useractivedeliverywindow.h \
    userorderlistwindow.h \
    usersmodel.h \
    workeractivedelivery.h \
    workeradddelivery.h \
    workereditdelivery.h \
    workereditproduct.h

FORMS += \
    adminwindow.ui \
    adminwindowdeluser.ui \
    authorization.ui \
    makeorder.ui \
    useractivedeliverywindow.ui \
    userorderlistwindow.ui \
    workeractivedelivery.ui \
    workeradddelivery.ui \
    workereditdelivery.ui \
    workereditproduct.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
