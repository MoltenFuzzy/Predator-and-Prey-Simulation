TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        creature.cpp \
        grid.cpp \
        main.cpp \
        predator.cpp \
        prey.cpp

HEADERS += \
    ../../!includes/Vector/vector.h \
    constants.h \
    creature.h \
    grid.h \
    predator.h \
    prey.h \
    wall.h \
    z_output.h \
    z_work_report.h
