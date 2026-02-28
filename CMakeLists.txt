cmake_minimum_required(VERSION 3.19)
project(cryostat LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets StateMachine Charts)

add_subdirectory(external)

include_directories("C:/Program Files/Andor SDK/")
include_directories("C:/Program Files/Andor SDK/Shamrock64/C/All")
link_directories("C:/Program Files/Andor SDK/")
link_directories("C:/Program Files/Andor SDK/Shamrock64/C/All")
include_directories("C:/Program Files/Andor SDK/ATSpectrograph")
link_directories("C:/Program Files/Andor SDK/ATSpectrograph/64")
qt_standard_project_setup()

set(PROJECT_SOURCES     main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    darkstyle.h
    darkstyle.cpp
    cryostat.h
    cryostat.cpp
    spectrometer.h
    spectrometer.cpp
    experiment.h
    experiment.cpp
    AppIcon.rc)

qt_add_resources(PROJECT_SOURCES resources/resources.qrc)

qt_add_executable(cryostat
    WIN32 MACOSX_BUNDLE
    ${PROJECT_SOURCES}
)

target_link_libraries(cryostat
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::StateMachine
        Qt6::Charts
        attolib
        atmcd64m
        ShamrockCIFm
        atspectrographm
)

include(GNUInstallDirs)

install(TARGETS cryostat
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET cryostat
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
