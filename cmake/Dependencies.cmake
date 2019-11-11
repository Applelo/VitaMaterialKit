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
        GIT_TAG        v4.5.95
)

FetchContent_Populate(unilib)
FetchContent_Populate(icon-font-cpp-headers)
FetchContent_Populate(materialdesign-webfont)

FetchContent_GetProperties(unilib)
FetchContent_GetProperties(icon-font-cpp-headers)
FetchContent_GetProperties(materialdesign-webfont)

#Unilib
if(NOT unilib_POPULATED)
    message("Install unilib")
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
    message("Install IconFontCppHeaders")
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
    message("Install MaterialDesign Webfont")
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