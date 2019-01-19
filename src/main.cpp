#include <psp2/kernel/processmgr.h>
#include "kit/core/App.hh"
#include "views/I18nSample.hh"
#include "views/ButtonsSample.hh"
#include "views/Welcome.hh"
#include "views/IconsSample.hh"
#include "views/TextsSample.hh"
#include "views/ImeSample.hh"

int main() {

    auto *welcome = new Welcome("Welcome");
    auto *i18nSample = new I18nSample("I18nSample");
    auto *buttonsSample = new ButtonsSample("ButtonsSample");
    auto *iconsSample = new IconsSample("IconsSample");
    auto *textsSample = new TextsSample("TextsSample");
    auto *imeSample = new ImeSample("ImeSample");
    
    auto *app = new App("Welcome");
    app->insertView(welcome);
    app->insertView(buttonsSample);
    app->insertView(i18nSample);
    app->insertView(iconsSample);
    app->insertView(imeSample);
    app->insertView(textsSample);

    app->main();

}
