#include "Ui.hh"

void Ui::init() {
    // For example
    // https://material.io/tools/color/#!/?view.left=0&view.right=0&primary.color=212121&secondary.color=90A4AE&secondary.text.color=FAFAFA&primary.text.color=FAFAFA
    colorSchemeHEX primaryThemeColor;
    colorSchemeHEX secondaryThemeColor;

    primaryThemeColor.normal = "#212121";
    primaryThemeColor.dark = "#000000";
    primaryThemeColor.light = "#484848";
    primaryThemeColor.text = "#fafafa";

    secondaryThemeColor.normal = "#90a4ae";
    secondaryThemeColor.dark = "#62757f";
    secondaryThemeColor.light = "#c1d5e0";
    secondaryThemeColor.text = "#fafafa";

    this->theme = new UiTheme(primaryThemeColor, secondaryThemeColor);
    this->texts = new UiTexts();
    this->icons = new UiIcons();
    this->buttons = new UiButtons(theme, texts, icons);
}


Ui::Ui() {
    this->icons = nullptr;
    this->texts = nullptr;
    this->buttons = nullptr;
    this->theme = nullptr;
    this->init();
}
