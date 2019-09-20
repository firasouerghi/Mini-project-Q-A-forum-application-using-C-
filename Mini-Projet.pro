#-------------------------------------------------
#
# Project created by QtCreator 2018-03-19T11:30:04
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mini-Projet
TEMPLATE = app

RC_ICONS = speech-bubble.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        landingpage.cpp \
    loginform.cpp \
    signupform.cpp \
    forumindex.cpp \
    dbqueries.cpp \
    homepageformember.cpp \
    homepageforadmin.cpp \
    controlpanel.cpp \
    Account.cpp \
    Admin.cpp \
    Category.cpp \
    Platform.cpp \
    PrivateMessage.cpp \
    Reply.cpp \
    Topic.cpp \
    userProfile.cpp \
    globalthings.cpp \
    displaycat.cpp \
    viewtopicwindow.cpp \
    createtopicpage.cpp \
    addreplypage.cpp \
    edittopicwindow.cpp \
    repliespage.cpp \
    writepm.cpp \
    showprofile.cpp
HEADERS += \
        landingpage.h \
    loginform.h \
    signupform.h \
    forumindex.h \
    dbqueries.h \
    homepageformember.h \
    homepageforadmin.h \
    controlpanel.h \
    Account.h \
    Admin.h \
    Category.h \
    Platform.h \
    PrivateMessage.h \
    Reply.h \
    Topic.h \
    userProfile.h \
    globalthings.h \
    displaycat.h \
    viewtopicwindow.h \
    createtopicpage.h \
    addreplypage.h \
    edittopicwindow.h \
    repliespage.h \
    writepm.h \
    showprofile.h

FORMS += \
        landingpage.ui \
    loginform.ui \
    signupform.ui \
    forumindex.ui \
    homepageformember.ui \
    homepageforadmin.ui \
    controlpanel.ui \
    displaycat.ui \
    viewtopicwindow.ui \
    createtopicpage.ui \
    addreplypage.ui \
    edittopicwindow.ui \
    repliespage.ui \
    writepm.ui \
    showprofile.ui
