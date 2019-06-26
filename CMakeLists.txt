cmake_minimum_required(VERSION 3.11)

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


set(SHORT_NAME VitaMaterialKit)
set(PSVITAIP "192.168.0.192")

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
set(VITA_VERSION "00.75")

include(cmake/Dependencies.txt)
include(cmake/Vita3K.txt)
include(cmake/Files.txt)
include(cmake/VitaMaterialKit.txt)

## Flags and includes for building
# Note that we make sure not to overwrite previous flags

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fpermissive -std=gnu11 -Wall ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive -std=c++11 -Wall ")

include_directories(
        ../common
)

add_executable(${SHORT_NAME}
        src/main.cpp

        ${MKIT_LIB}
        ${MKIT_CORE}
        ${MKIT_UI}
        ${MKIT_UTILS}

        src/app/views/Welcome.cpp
        src/app/views/I18nSample.cpp
        src/app/views/ButtonsSample.cpp
        src/app/views/IconsSample.cpp
        src/app/views/TextsSample.cpp
        src/app/views/CheckboxesSample.cpp
        src/app/views/TextFieldsSample.cpp
        src/app/views/CardsSample.cpp
        )


# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${SHORT_NAME}
        vita2d
        SceDisplay_stub
        SceGxm_stub
        ScePvf_stub
        SceSysmodule_stub
        SceCtrl_stub
        SceTouch_stub
        SceCommonDialog_stub
        SceAppUtil_stub
        SceRegistryMgr_stub
        jansson
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
        FILE ${FILES_SCE_SYS} ${FILES_FONTS} ${FILES_LANGUAGES}
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

add_custom_target(emulate
        COMMAND cp eboot.bin ${VITA3K_FOLDER_PATH}/eboot.bin
        COMMAND ${VITA3K_APP_PATH} -r ${VITA_TITLEID}
        DEPENDS eboot.bin
        )

add_custom_target(emulate_vpk
        COMMAND ${VITA3K_APP_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${SHORT_NAME}.vpk
        DEPENDS ${SHORT_NAME}.vpk
        )

