QT       += core gui
INCLUDEPATH += D:\vcpkg\vcpkg-master\installed\x64-windows\include
LIBS += -LD:\vcpkg\vcpkg-master\installed\x64-windows\lib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    reader.cpp \
    reader_page.cpp \
    regula_all.cpp \
    regula_book_page.cpp \
    regula_reader_page.cpp \
    system.cpp

HEADERS += \
    book.h \
    book_table_modle.h \
    global.h \
    mainwindow.h \
    reader.h \
    reader_page.h \
    reader_table_modle.h \
    regula_all.h \
    regula_book_page.h \
    regula_reader_page.h \
    system.h

FORMS += \
    mainwindow.ui \
    reader_page.ui \
    regula_all.ui \
    regula_book_page.ui \
    regula_reader_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
