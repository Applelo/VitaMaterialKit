#include <psp2/kernel/processmgr.h>
#include "kit/core/App.hh"
#include "views/I18nSample.hh"
#include "views/ButtonsSample.hh"
#include "views/Welcome.hh"
#include "views/IconsSample.hh"
#include "views/TextsSample.hh"
#include "views/CheckboxesSample.hh"
#include "views/TextFieldsSample.hh"
#include "views/CardsSample.hh"

int main() {

    auto *welcome = new Welcome("Welcome");
    auto *i18nSample = new I18nSample("I18nSample");
    auto *buttonsSample = new ButtonsSample("ButtonsSample");
    auto *iconsSample = new IconsSample("IconsSample");
    auto *textsSample = new TextsSample("TextsSample");
    auto *checkboxesSample = new CheckboxesSample("CheckboxesSample");
    auto *textFieldsSample = new TextFieldsSample("TextFieldsSample");
    auto *cardsSample = new CardsSample("CardsSample");

    auto *app = new App("Welcome");

    app->insertView(welcome);
    app->insertView(buttonsSample);
    app->insertView(i18nSample);
    app->insertView(iconsSample);
    app->insertView(textsSample);
    app->insertView(checkboxesSample);
    app->insertView(textFieldsSample);
    app->insertView(cardsSample);

    app->main();

}
