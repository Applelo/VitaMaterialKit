#ifndef VITAMATERIALKIT_UIPARENTBOXES_HH
#define VITAMATERIALKIT_UIPARENTBOXES_HH

#include "../UiTheme.hpp"
#include "../UiTexts.hpp"
#include "../UiIcons.hpp"

#define BOXES_DEFAULT_SIZE 40

class UiParentBoxes {
private:
    unsigned int selectorColor;
    UiTheme *theme;
    UiIcons *icons;
    UiTexts *texts;
protected:
    UiParentBoxes(UiTheme *theme);
    UiParentBoxes(UiTheme *theme, UiIcons *icons);
    UiParentBoxes(UiTheme *theme, UiIcons *icons, UiTexts *texts);

    void drawSelector(int x, int y, bool selector, unsigned int size = BOXES_DEFAULT_SIZE);

    TextData drawText(int x, int y, int size, std::string text);

    void drawBoxButton(int x, int y, const char* icon, unsigned int size = BOXES_DEFAULT_SIZE);
    void drawBoxButtonColor(int x, int y, const char* icon, unsigned int color, unsigned int size = BOXES_DEFAULT_SIZE);

};


#endif //VITAMATERIALKIT_UIPARENTBOXES_HH
