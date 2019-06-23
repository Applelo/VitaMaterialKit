#ifndef VITAMATERIALKIT_UI_HH
#define VITAMATERIALKIT_UI_HH


#include "ui/UiTheme.hh"
#include "ui/UiIcons.hh"
#include "ui/UiTexts.hh"
#include "ui/UiButtons.hh"
#include "ui/UiCheckboxes.hh"
#include "ui/UiTextFields.hh"
#include "ui/UiRadioBoxes.hh"
#include "ui/UiCards.hh"


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
