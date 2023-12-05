QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    FlyingObject/FlyingObjectParameters.cpp \
    Patterns/HeightParameterWindow.cpp \
    OpenGLWidget/OpenGLWidget.cpp \
    Patterns/ReverseParameterWindow.cpp \
    Patterns/SpeedParameterWindow.cpp \
    RLS/RLS.cpp \
    mainwindow.cpp \
    ../src/Manager.cpp \
    ../src/air_models/AbstractAirObject.cpp \
    ../src/air_models/Plane.cpp \
    ../src/handler/Solver.cpp \
    ../src/handler/CollisionsHandling.cpp \
    ../src/math/Calculating.cpp \
    ../src/patterns/AbstractAirModelPattern.cpp \
    ../src/patterns/ChangeHeightPattern.cpp \
    ../src/patterns/ChangeSpeedPattern.cpp \
    ../src/patterns/LinearPattern.cpp \
    ../src/patterns/ReversalPattern.cpp \
    ../src/rls/Emitter.cpp \
    ../src/rls/RadioDetectionAndRangingModel.cpp \
    ../src/rls/Reciever.cpp \
    ../src/Signal.cpp \
    ../src/tracker/Aim.cpp \
    ../src/tracker/Tracker.cpp \
    ../src/utils/Vec3.cpp \
    ../src/utils/Matrix.cpp


HEADERS += \
    FlyingObject/FlyingObjectParameters.h \
    Patterns/HeightParameterWindow.h \
    OpenGLWidget/OpenGLWidget.h \
    Patterns/ReverseParameterWindow.h \
    Patterns/SpeedParameterWindow.h \
    Camera/Camera.h \
    mainwindow.h \
    RLS/RLS.h \
    Library/stb_image.h \
    ../src/Manager.hpp \
    ../src/air_models/AbstractAirObject.hpp \
    ../src/air_models/Plane.hpp \
    ../src/handler/Solver.hpp \
    ../src/handler/CollisionsHandling.hpp \
    ../src/math/ErrorHandler.hpp \
    ../src/math/ReflectiveErrorSignalHandler.hpp \
    ../src/math/Calculating.hpp \
    ../src/patterns/AbstractAirModelPattern.hpp \
    ../src/patterns/ChangeHeightPattern.hpp \
    ../src/patterns/ChangeSpeedPattern.hpp \
    ../src/patterns/LinearPattern.hpp \
    ../src/patterns/ReversalPattern.hpp \
    ../src/rls/Emitter.hpp \
    ../src/rls/RadioDetectionAndRangingModel.hpp \
    ../src/rls/Reciever.hpp \
    ../src/Signal.hpp \
    ../src/tracker/Aim.hpp \
    ../src/tracker/Tracker.hpp \
    ../src/utils/Vec3.hpp \
    ../src/utils/Matrix.hpp

FORMS += \
    FlyingObject/FlyingObjectParameters.ui \
    Patterns/HeightParameterWindow.ui \
    Patterns/ReverseParameterWindow.ui \
    Patterns/SpeedParameterWindow.ui \
    mainwindow.ui \
    RLS/RLS.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -framework GLUT

RESOURCES += \
    Resources
