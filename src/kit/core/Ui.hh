#ifndef VITAMATERIALKIT_UI_HH
#define VITAMATERIALKIT_UI_HH


#include "../ui/UiTheme.hpp"
#include "../ui/UiIcons.hpp"
#include "../ui/UiTexts.hpp"
#include "../ui/UiButtons.hpp"

//if you don't want to load all ui, override initUi function, to set your own theme override initTheme option
class Ui {
public:
    UiTheme *theme;
    UiTexts *texts;
    UiButtons *buttons;
    UiIcons icons;

    std::map<std::string, vita2d_font*> roboto;
    vita2d_font *mdi;

    Ui();
    void loadFonts();

    virtual void init();
};


#endif //VITAMATERIALKIT_UI_HH
