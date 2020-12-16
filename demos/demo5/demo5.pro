#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T22:19:03
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = demo5
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    demo5.cpp

## Location of SMTP Library
#SMTP_LIBRARY_LOCATION = $$PWD/../../../build/SMTPEmail-Desktop-Debug

#win32:CONFIG(release, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/release/ -lSMTPEmail
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/debug/ -lSMTPEmail
#else:unix: LIBS += -L$$SMTP_LIBRARY_LOCATION -lSMTPEmail

#INCLUDEPATH += $$SMTP_LIBRARY_LOCATION
#DEPENDPATH += $$SMTP_LIBRARY_LOCATION


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-SMTPEmail-Desktop_Qt_5_6_3_MSVC2015_32bit-Debug/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-SMTPEmail-Desktop_Qt_5_6_3_MSVC2015_32bit-Debug/debug/ -lSMTPEmail

INCLUDEPATH += $$PWD/../../../build-SMTPEmail-Desktop_Qt_5_6_3_MSVC2015_32bit-Debug/debug
DEPENDPATH += $$PWD/../../../build-SMTPEmail-Desktop_Qt_5_6_3_MSVC2015_32bit-Debug/debug
