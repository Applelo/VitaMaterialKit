#include "Ui.hh"

Ui::Ui() {
    this->initTheme();
    this->init();
}

void Ui::init() {
    this->theme     = new UiTheme(primaryThemeColor, secondaryThemeColor);
    this->texts     = new UiTexts(this->theme);
    this->icons     = new UiIcons(this->theme);
    this->buttons   = new UiButtons(this->theme, this->texts, this->icons);
    this->checkboxes = new UiCheckboxes(this->theme, this->icons);
}

void Ui::initTheme() {
    // For example
    // https://material.io/tools/color/#!/?view.left=0&view.right=0&primary.color=212121&secondary.color=90A4AE&secondary.text.color=FAFAFA&primary.text.color=FAFAFA
    primaryThemeColor.normal = "#212121";
    primaryThemeColor.dark = "#000000";
    primaryThemeColor.light = "#484848";
    primaryThemeColor.text = "#fafafa";

    secondaryThemeColor.normal = "#90a4ae";
    secondaryThemeColor.dark = "#62757f";
    secondaryThemeColor.light = "#c1d5e0";
    secondaryThemeColor.text = "#fafafa";
}