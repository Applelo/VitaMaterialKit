#VITAMATERIALKIT
set(MKIT_LIB
        src/kit/lib/unilib/unicode.cpp
        src/kit/lib/unilib/utf8.cpp
        )

set(MKIT_CORE
        src/kit/core/App.cpp
        src/kit/core/Debug.cpp
        src/kit/core/EventUi.cpp
        src/kit/core/ViewsController.cpp
        src/kit/core/View.cpp
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