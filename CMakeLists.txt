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
set(VITA_VERSION "00.70")


#Download and install externals dependencies only the first cmake load
include(FetchContent)
FetchContent_Declare(
        unilib
        GIT_REPOSITORY https://github.com/ufal/unilib.git
        GIT_TAG        v3.1.1
)
FetchContent_Declare(
        icon-font-cpp-headers
        GIT_REPOSITORY https://github.com/juliettef/IconFontCppHeaders
)

FetchContent_Declare(
        materialdesign-webfont
        GIT_REPOSITORY https://github.com/Templarian/MaterialDesign-Webfont.git
        GIT_TAG        v3.6.95
)

FetchContent_Populate(unilib)
FetchContent_Populate(icon-font-cpp-headers)
FetchContent_Populate(materialdesign-webfont)

FetchContent_GetProperties(unilib)
FetchContent_GetProperties(icon-font-cpp-headers)
FetchContent_GetProperties(materialdesign-webfont)

#Unilib
if(NOT unilib_POPULATED)
    set(UNILIB_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/kit/lib/unilib/)
    file(REMOVE_RECURSE ${UNILIB_LOCATION}*)
    file(COPY
            ${unilib_SOURCE_DIR}/unilib/unicode.cpp
            DESTINATION ${UNILIB_LOCATION}
    )
    file(COPY
            ${unilib_SOURCE_DIR}/unilib/unicode.h
            DESTINATION ${UNILIB_LOCATION}
            )
    file(COPY
            ${unilib_SOURCE_DIR}/unilib/utf8.cpp
            DESTINATION ${UNILIB_LOCATION}
            )
    file(COPY
            ${unilib_SOURCE_DIR}/unilib/utf8.h
            DESTINATION ${UNILIB_LOCATION}
            )
    file(COPY
            ${unilib_SOURCE_DIR}/LICENSE
            DESTINATION ${UNILIB_LOCATION}
            )
endif()

#IconFontCppHeaders
if(NOT icon-font-cpp-headers_POPULATED)
    set(IFCH_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/kit/lib/IconFontCppHeaders)
    file(REMOVE_RECURSE ${IFCH_LOCATION}*)
    file(COPY
            ${icon-font-cpp-headers_SOURCE_DIR}/IconsMaterialDesignIcons.h
            DESTINATION ${IFCH_LOCATION}
            )
    file(COPY
            ${icon-font-cpp-headers_SOURCE_DIR}/licence.txt
            DESTINATION ${IFCH_LOCATION}
            )
endif()

#MaterialDesign Webfont
if(NOT materialdesignicons-webfont_POPULATED)
    set(MDI_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/assets/fonts/mdi/)
    file(REMOVE_RECURSE ${MDI_LOCATION}*)
    file(COPY
            ${materialdesign-webfont_SOURCE_DIR}/fonts/materialdesignicons-webfont.ttf
            DESTINATION ${MDI_LOCATION}
    )
    file(COPY
            ${materialdesign-webfont_SOURCE_DIR}/license.md
            DESTINATION ${MDI_LOCATION}
            )
endif()


#Vita3K
set(VITA3K_APP_PATH "/Applications/Vita3K.app/Contents/MacOS/Vita3K")
set(VITA3K_FOLDER_PATH "/Users/Applelo/Library/Application\ Support/Vita3K/Vita3K/ux0/app/${VITA_TITLEID}")

#Files
set(FILES_SCE_SYS
        sce_sys/icon0.png                       sce_sys/icon0.png
        sce_sys/livearea/pic0.png               sce_sys/livearea/pic0.png
        sce_sys/livearea/contents/bg.png        sce_sys/livearea/contents/bg.png
        sce_sys/livearea/contents/startup.png   sce_sys/livearea/contents/startup.png
        sce_sys/livearea/contents/template.xml  sce_sys/livearea/contents/template.xml
        )

set(FILES_FONTS
        assets/fonts/mdi/materialdesignicons-webfont.ttf    assets/fonts/mdi/materialdesignicons-webfont.ttf
        assets/fonts/Roboto/Roboto-Black.ttf                assets/fonts/Roboto/Roboto-Black.ttf
        assets/fonts/Roboto/Roboto-BlackItalic.ttf          assets/fonts/Roboto/Roboto-BlackItalic.ttf
        assets/fonts/Roboto/Roboto-Bold.ttf                 assets/fonts/Roboto/Roboto-Bold.ttf
        assets/fonts/Roboto/Roboto-BoldItalic.ttf           assets/fonts/Roboto/Roboto-BoldItalic.ttf
        assets/fonts/Roboto/Roboto-Italic.ttf               assets/fonts/Roboto/Roboto-Italic.ttf
        assets/fonts/Roboto/Roboto-Light.ttf                assets/fonts/Roboto/Roboto-Light.ttf
        assets/fonts/Roboto/Roboto-LightItalic.ttf          assets/fonts/Roboto/Roboto-LightItalic.ttf
        assets/fonts/Roboto/Roboto-Medium.ttf               assets/fonts/Roboto/Roboto-Medium.ttf
        assets/fonts/Roboto/Roboto-MediumItalic.ttf         assets/fonts/Roboto/Roboto-MediumItalic.ttf
        assets/fonts/Roboto/Roboto-Regular.ttf              assets/fonts/Roboto/Roboto-Regular.ttf
        assets/fonts/Roboto/Roboto-Thin.ttf                 assets/fonts/Roboto/Roboto-Thin.ttf
        assets/fonts/Roboto/Roboto-ThinItalic.ttf           assets/fonts/Roboto/Roboto-ThinItalic.ttf
        )

set(FILES_LANGUAGES
        i18n/en_us.json i18n/en_us.json
        i18n/fr.json    i18n/fr.json
        )

#VITAMATERIALKIT
set(MKIT_LIB
        src/kit/lib/unilib/unicode.cpp
        src/kit/lib/unilib/utf8.cpp
        )

set(MKIT_CORE
        src/kit/core/App.cpp
        src/kit/core/ViewsController.cpp
        src/kit/core/View.cpp
        src/kit/core/EventUi.cpp
        )

set(MKIT_UI
        src/app/Ui.cpp
        src/kit/ui/parent/UiParentBoxes.cpp
        src/kit/ui/UiTheme.cpp
        src/kit/ui/UiIcons.cpp
        src/kit/ui/UiButtons.cpp
        src/kit/ui/UiTexts.cpp
        src/kit/ui/UiCheckboxes.cpp
        src/kit/ui/UiTextFields.cpp
        src/kit/ui/UiRadioBoxes.cpp
        src/kit/ui/UiCards.cpp
        )

set(MKIT_UTILS
        src/app/Utils.cpp
        src/kit/utils/UtilsI18n.cpp
        src/kit/utils/UtilsIME.cpp
        src/kit/utils/UtilsPad.cpp
        src/kit/utils/UtilsTouch.cpp
        src/kit/utils/UtilsPadTouchCtrl.cpp
        src/kit/utils/UtilsScroll.cpp
        )

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

