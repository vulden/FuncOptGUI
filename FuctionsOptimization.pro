QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Area.cpp \
    FuncOpt.cpp \
    OptMethod.cpp \
    StopCriterion.cpp \
    areadialog.cpp \
    coorddescdial.cpp \
    localsdial.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    stopcrit1.cpp \
    stopcrit2.cpp

HEADERS += \
    area.h \
    areadialog.h \
    coorddescdial.h \
    funcOpt.h \
    localsdial.h \
    mainwindow.h \
    optmethod.h \
    qcustomplot.h \
    stopCrit.h \
    stopcrit1.h \
    stopcrit2.h

FORMS += \
    areadialog.ui \
    coorddescdial.ui \
    localsdial.ui \
    mainwindow.ui \
    stopcrit1.ui \
    stopcrit2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
