#ifndef VITAMATERIALKIT_UI_HH
#define VITAMATERIALKIT_UI_HH


#include "../kit/ui/UiTheme.hh"
#include "../kit/ui/UiIcons.hh"
#include "../kit/ui/UiTexts.hh"
#include "../kit/ui/UiButtons.hh"
#include "../kit/ui/UiCheckboxes.hh"
#include "../kit/ui/UiTextFields.hh"
#include "../kit/ui/UiRadioBoxes.hh"
#include "../kit/ui/UiCards.hh"


class Ui {
protected:
    colorSchemeHEX primaryThemeColor;
    colorSchemeHEX secondaryThemeColor;
    void initTheme();
    void init();
public:
    UiTheme *theme;
    UiTexts *texts;
    UiButtons *buttons;
    UiIcons *icons;
    UiCheckboxes *checkboxes;
    UiTextFields *textFields;
    UiRadioBoxes *radioBoxes;
    UiCards *cards;

    Ui();
};


#endif //VITAMATERIALKIT_UI_HH
