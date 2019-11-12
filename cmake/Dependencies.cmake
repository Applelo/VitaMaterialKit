set(IFCH_FILES_COPY
"IconsMaterialDesignIcons.h"
"licence.txt"
)

set(MDI_FILES_COPY
"fonts/materialdesignicons-webfont.ttf"
"license.md"
)

set(UNILIB_FILES_COPY
"unilib/unicode.cpp"
"unilib/unicode.h"
"unilib/utf8.cpp"
"unilib/utf8.h"
"LICENSE"
)

install_dep(
        "icon-font-cpp-headers"
        "https://github.com/juliettef/IconFontCppHeaders"
        "8a8e4a3ec40a9d8fc4d87614f02ed78f29836f62"
        "src/kit/lib/IconFontCppHeaders"
        "${IFCH_FILES_COPY}"
)

install_dep(
        "materialdesignicons-webfont"
        "https://github.com/Templarian/MaterialDesign-Webfont.git"
        "v4.5.95"
        "assets/fonts/mdi"
        "${MDI_FILES_COPY}"
)

install_dep(
        "unilib"
        "https://github.com/ufal/unilib.git"
        "v3.1.1"
        "src/kit/lib/unilib"
        "${UNILIB_FILES_COPY}"
)