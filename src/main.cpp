#include "kit/ui/Theme.hpp"
#include "kit/core/App.hh"
#include "views/Welcome.hh"

int main() {

    Ui *ui;
    ui = new Ui();

    Welcome *welcome;
    welcome = new Welcome("Welcome");

    auto *app = new App(ui, "Welcome");
    app->insertView(welcome);

    app->main();

    return 0;
}
