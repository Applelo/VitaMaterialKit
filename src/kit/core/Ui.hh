#ifndef VITAMATERIALKIT_UI_HH
#define VITAMATERIALKIT_UI_HH


#include "../ui/UiTheme.hpp"
#include "../ui/UiIcons.hpp"
#include "../ui/UiTexts.hpp"
#include "../ui/UiButtons.hpp"

//if you don't want to load all ui, override initUi function
class Ui {
public:
    UiTheme *theme;
    UiTexts *texts;
    UiButtons *buttons;
    UiIcons *icons;

    Ui();

    virtual void init();
};


#endif //VITAMATERIALKIT_UI_HH
