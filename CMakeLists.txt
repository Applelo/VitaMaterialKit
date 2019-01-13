## This file is a quick tutorial on writing CMakeLists for targeting the Vita
cmake_minimum_required(VERSION 2.8)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is
# highly recommended that you include this block for all projects.
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (DEFINED ENV{VITASDK})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
    else ()
        message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
    endif ()
endif ()

## Define project parameters here
# Name of the project
set(SHORT_NAME VitaMaterialKit)
set(PSVITAIP "192.168.1.37")
set(VITA3K_PATH "/Applications/Vita3K.app/Contents/MacOS/Vita3K")
project(${SHORT_NAME})
# This line adds Vita helper macros, must go after project definition in order
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
# Display name (under bubble in LiveArea)
set(VITA_APP_NAME "VitaMaterialKit")
# Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X =
# unique string of developer and Y = a unique number for this app

set(VITA_TITLEID "MKIT00001")
# Optional version string to show in LiveArea's more info screen
set(VITA_VERSION "01.00")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fpermissive -std=gnu11 -Wall ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive -std=c++11 -Wall ")

include_directories(
        ../common
)

add_executable(${SHORT_NAME}
        src/main.cpp
        src/kit/ui/Texts.cpp
        src/kit/ui/Theme.cpp
        src/kit/ui/Icons.cpp
        src/kit/ui/Buttons.cpp
        )

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${SHORT_NAME}
        vita2d
        SceDisplay_stub
        SceGxm_stub
        SceSysmodule_stub
        SceCtrl_stub
        ScePvf_stub
        SceCommonDialog_stub
        SceNet_stub_weak
        SceNetCtl_stub_weak
        freetype
        png
        jpeg
        z
        m
        c
        )


vita_create_self(eboot.bin ${SHORT_NAME})
vita_create_vpk(${SHORT_NAME}.vpk ${VITA_TITLEID} eboot.bin
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FILE sce_sys/icon0.png      sce_sys/icon0.png
        sce_sys/livearea/pic0.png   sce_sys/livearea/pic0.png
        sce_sys/livearea/contents/bg.png        sce_sys/livearea/contents/bg.png
        sce_sys/livearea/contents/startup.png   sce_sys/livearea/contents/startup.png
        sce_sys/livearea/contents/template.xml  sce_sys/livearea/contents/template.xml

        assets/fonts/mdi/materialdesignicons-webfont.ttf assets/fonts/mdi/materialdesignicons-webfont.ttf
        assets/fonts/Roboto/Roboto-Black.ttf        assets/fonts/Roboto/Roboto-Black.ttf
        assets/fonts/Roboto/Roboto-BlackItalic.ttf  assets/fonts/Roboto/Roboto-BlackItalic.ttf
        assets/fonts/Roboto/Roboto-Bold.ttf         assets/fonts/Roboto/Roboto-Bold.ttf
        assets/fonts/Roboto/Roboto-BoldItalic.ttf   assets/fonts/Roboto/Roboto-BoldItalic.ttf
        assets/fonts/Roboto/Roboto-Italic.ttf       assets/fonts/Roboto/Roboto-Italic.ttf
        assets/fonts/Roboto/Roboto-Light.ttf        assets/fonts/Roboto/Roboto-Light.ttf
        assets/fonts/Roboto/Roboto-LightItalic.ttf  assets/fonts/Roboto/Roboto-LightItalic.ttf
        assets/fonts/Roboto/Roboto-Medium.ttf       assets/fonts/Roboto/Roboto-Medium.ttf
        assets/fonts/Roboto/Roboto-MediumItalic.ttf assets/fonts/Roboto/Roboto-MediumItalic.ttf
        assets/fonts/Roboto/Roboto-Regular.ttf      assets/fonts/Roboto/Roboto-Regular.ttf
        assets/fonts/Roboto/Roboto-Thin.ttf         assets/fonts/Roboto/Roboto-Thin.ttf
        assets/fonts/Roboto/Roboto-ThinItalic.ttf   assets/fonts/Roboto/Roboto-ThinItalic.ttf

        i18n/en.json i18n/en.json
        i18n/fr.json i18n/fr.json
        )


add_custom_target(send
        COMMAND curl -T eboot.bin ftp://${PSVITAIP}:1337/ux0:/app/${VITA_TITLEID}/
        DEPENDS eboot.bin
        )

add_custom_target(copy
        COMMAND cp eboot.bin F:/app/${VITA_TITLEID}/eboot.bin
        DEPENDS eboot.bin
        )

add_custom_target(send_vpk
        COMMAND curl -T ${SHORT_NAME}.vpk ftp://${PSVITAIP}:1337/ux0:/data/
        DEPENDS ${SHORT_NAME}.vpk
        )

add_custom_target(copy_vpk
        COMMAND cp ${SHORT_NAME}.vpk F:/data/${VITA_TITLEID}/${SHORT_NAME}.vpk
        DEPENDS ${SHORT_NAME}.vpk
        )

add_custom_target(emulator
        COMMAND ${VITA3K_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${SHORT_NAME}.vpk
        DEPENDS ${SHORT_NAME}.vpk
        )
