#ifndef VITAMATERIALKIT_UIPARENTBOXBUTTONS_HH
#define VITAMATERIALKIT_UIPARENTBOXBUTTONS_HH

#include "../UiTheme.hpp"
#include "../UiTexts.hpp"
#include "../UiIcons.hpp"

#define BOXBUTTONS_DEFAULT_SIZE 40

class UiParentBoxButtons {
private:
    unsigned int selectorColor;
    UiTheme *theme;
    UiIcons *icons;
    UiTexts *texts;
protected:
    UiParentBoxButtons(UiTheme *theme);
    UiParentBoxButtons(UiTheme *theme, UiIcons *icons);
    UiParentBoxButtons(UiTheme *theme, UiIcons *icons, UiTexts *texts);

    void drawSelector(int x, int y, bool selector, unsigned int size = BOXBUTTONS_DEFAULT_SIZE);

    void drawText(int x, int y, int size, std::string text);

    void drawBoxButton(int x, int y, const char* icon, unsigned int size = BOXBUTTONS_DEFAULT_SIZE);
    void drawBoxButtonColor(int x, int y, const char* icon, unsigned int color, unsigned int size = BOXBUTTONS_DEFAULT_SIZE);

};


#endif //VITAMATERIALKIT_UIPARENTBOXBUTTONS_HH
