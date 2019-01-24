#ifndef VITAMATERIALKIT_UITEXTFIELDS_HH
#define VITAMATERIALKIT_UITEXTFIELDS_HH

#include "../core/UiEvent.hh"
#include "UiTheme.hpp"
#include "UiIcons.hpp"
#include "UiTexts.hpp"
#include <string>

//https://material.io/design/components/text-fields.html

//positions / dimensions
#define TEXTFIELD_PADDING 20
#define TEXTFIELD_WIDTH 300
#define TEXTFIELD_HEIGTH 76

//colors
#define TEXTFIELD_BACKGROUND_NOFOCUS_COLOR (unsigned int) RGBA8(242, 242, 242, 255)
#define TEXTFIELD_BACKGROUND_FOCUS_COLOR (unsigned int) RGBA8(212, 212, 212, 255)
#define TEXTFIELD_NOFOCUSBAR_COLOR (unsigned int) RGBA8(122, 122, 122, 255)
#define TEXTFIELD_ERROR_COLOR (unsigned int) RGBA8(159, 0, 25, 255)
#define TEXTFIELD_HELPER_COLOR (unsigned int) RGBA8(91, 91, 91, 255)



typedef struct ZoneEventTextField : public ZoneEvent {
    ZoneEvent leadingIcon;
    ZoneEvent trailingIcon;
    std::string text;
} ZoneEventTextField;

class UiTextFields : public UiEvent {
private:
    UiTheme *theme;
    UiTexts *texts;
    UiIcons *icons;
    ZoneEventTextField zoneEventTextField;
    TextStyleData bottomTextStyleData, mainTextStyleData;
    TextData textDataText;
    int prefixPos, suffixPos;
    void init();
public:
    UiTextFields(UiTheme *theme);
    UiTextFields(UiTheme *theme, UiTexts *texts);
    UiTextFields(UiTheme *theme, UiTexts *texts, UiIcons *icons);


    ZoneEventTextField filledDraw(
            int x,
            int y,
            bool selector,
            std::string label,
            std::string text = "",
            TypeTheme typeTheme = THEME_PRIMARY,
            std::string helperText = "",
            std::string errorText = "",
            const char *leadingIcon = "",
            const char *trailingIcon = "",
            std::string prefixText = "",
            std::string suffixText = "",
            int charCounter = 0
            );



};


#endif //VITAMATERIALKIT_UITEXTFIELDS_HH
