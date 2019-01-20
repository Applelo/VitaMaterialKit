#ifndef VITAMATERIALKIT_UI_HH
#define VITAMATERIALKIT_UI_HH


#include "../ui/UiTheme.hpp"
#include "../ui/UiIcons.hpp"
#include "../ui/UiTexts.hpp"
#include "../ui/UiButtons.hpp"

//if you don't want to load all ui, override initUi function, to set your own theme override initTheme option
class Ui {
protected:
    colorSchemeHEX primaryThemeColor;
    colorSchemeHEX secondaryThemeColor;
    virtual void initTheme();
    virtual void init();
public:
    UiTheme *theme;
    UiTexts *texts;
    UiButtons *buttons;
    UiIcons *icons;

    Ui();
};


#endif //VITAMATERIALKIT_UI_HH
