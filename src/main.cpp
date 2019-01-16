#include "kit/ui/UiTheme.hpp"
#include "kit/core/App.hh"
#include "views/Welcome.hh"
#include "views/Texts.hh"

int main() {

    Ui *ui;
    ui = new Ui();

    Welcome *welcome;
    welcome = new Welcome("Welcome");

    Texts *texts;
    texts = new Texts("Texts");

    auto *app = new App(ui, "Welcome");
    app->insertView(welcome);
    app->insertView(texts);

    app->main();

    return 0;
}
