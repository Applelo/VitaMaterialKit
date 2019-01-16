#ifndef VITAMATERIALKIT_UI_HH
#define VITAMATERIALKIT_UI_HH


#include "../ui/Theme.hpp"
#include "../ui/Icons.hpp"
#include "../ui/Texts.hpp"
#include "../ui/Buttons.hpp"

//if you don't want to load all ui, override initUi function
class Ui {
public:
    Theme *theme;
    Texts *texts;
    Buttons *buttons;
    Icons *icons;

    Ui();

    virtual void init();
};


#endif //VITAMATERIALKIT_UI_HH
