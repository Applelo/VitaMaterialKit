#include "kit/ui/Theme.hpp"
#include "kit/core/App.hh"
#include "views/Welcome.hh"

int main() {


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

    Theme *theme;
    theme = new Theme(primaryThemeColor, secondaryThemeColor);

    Welcome *welcome;
    welcome = new Welcome("Welcome");

    auto *app = new App(theme, "Welcome");
    app->insertView(welcome);

    app->main();

    return 0;
}
