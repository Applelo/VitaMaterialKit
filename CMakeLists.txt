cmake_minimum_required(VERSION 3.11)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (DEFINED ENV{VITASDK})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
    else ()
        message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
    endif ()
endif ()

project(VitaMaterialKit)
include("${VITASDK}/share/vita.cmake" REQUIRED)

include(cmake/Config.cmake)
include(cmake/Dependencies.cmake)
include(cmake/Vita3K.cmake)
include(cmake/Files.cmake)
include(cmake/VitaMaterialKit.cmake)

## Flags and includes for building
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fpermissive -std=gnu11 -Wall ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive -std=c++11 -Wall ")

add_executable(${PROJECT_NAME}
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

#Add definitions
add_definitions(-DDEBUG_LOG_DIR="${DEBUG_LOG_DIR}" -DDEBUG_NET_IP="${DEBUG_NET_IP}" )
target_compile_definitions(${PROJECT_NAME} PRIVATE
        DEBUG_NET=${DEBUG_NET}
        DEBUG_NET_PORT=${DEBUG_NET_PORT}
        DEBUG_LOG=${DEBUG_LOG}
        VMKIT_VERSION=${VITA_VERSION})
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_APP=1)
    if (${DEBUG_NET} EQUAL 1)
        target_link_libraries(${PROJECT_NAME}
                debugnet
                SceNetCtl_stub
                SceNet_stub)
    endif ()
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_APP=0)
endif()


# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${PROJECT_NAME}
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

vita_create_self(eboot.bin ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} eboot.bin
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FILE ${FILES_SCE_SYS} ${FILES_FONTS} ${FILES_LANGUAGES}
        )

#Send through the FTP
add_custom_target(send
        COMMAND curl -T eboot.bin ftp://${PSVITA_IP}:1337/ux0:/app/${VITA_TITLEID}/
        DEPENDS eboot.bin
        )

add_custom_target(send_vpk
        COMMAND curl -T ${PROJECT_NAME}.vpk ftp://${PSVITA_IP}:1337/ux0:/data/
        DEPENDS ${PROJECT_NAME}.vpk
        )

#Copy to the device
add_custom_target(copy
        COMMAND cp eboot.bin ${PSVITA_VOLUME}app/${VITA_TITLEID}/eboot.bin
        DEPENDS eboot.bin
        )

add_custom_target(copy_vpk
        COMMAND cp ${PROJECT_NAME}.vpk ${PSVITA_VOLUME}data/${VITA_TITLEID}/${PROJECT_NAME}.vpk
        DEPENDS ${PROJECT_NAME}.vpk
        )

#Vita3K
add_custom_target(emulate
        COMMAND cp eboot.bin ${VITA3K_FOLDER_PATH}/eboot.bin
        COMMAND ${VITA3K_APP_PATH} -r ${VITA_TITLEID}
        DEPENDS eboot.bin
        )

add_custom_target(emulate_vpk
        COMMAND ${VITA3K_APP_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.vpk
        DEPENDS ${PROJECT_NAME}.vpk
        )

