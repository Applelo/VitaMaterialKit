#include <psp2/kernel/processmgr.h>
#include "kit/core/App.hh"
#include "views/Welcome.hh"
#include "views/ButtonsSample.hh"

#define DEBUG 1

int main() {

    auto *welcome = new Welcome("Welcome");
    auto *buttonsSample = new ButtonsSample("ButtonsSample");
    
    auto *app = new App("Welcome");
    app->insertView(welcome);
    app->insertView(buttonsSample);

    app->main();

}
