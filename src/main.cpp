#include "kit/ui/UiTheme.hpp"
#include "kit/core/App.hh"
#include "views/Welcome.hh"

#include <psp2/kernel/processmgr.h>

#include "kit/core/Ui.hh"
#include "kit/core/App.hh"
#include "views/Welcome.hh"

int main() {

    auto *ui = new Ui();
    auto *welcome = new Welcome("Welcome");
    auto *app = new App(ui, "Welcome");
    app->insertView(welcome);

    return app->main();

}
