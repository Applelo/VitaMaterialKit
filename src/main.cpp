#include "kit/ui/UiTheme.hpp"
#include "kit/core/App.hh"
#include "views/Welcome.hh"

int main() {

    Ui ui;
    ui = Ui();


    /*Welcome *welcome;
    welcome = new Welcome("Welcome");

    auto *app = new App(ui, "Welcome");
    app->insertView(welcome);

    app->main();*/


    vita2d_init();
    vita2d_set_clear_color((unsigned int) RGBA8(218, 219, 219, 255));

    while (1) {
        vita2d_start_drawing();
        vita2d_clear_screen();


        ui.icons.draw(ICON_MDI_ACCESS_POINT, 0,0);

        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();
    sceKernelExitProcess(0);

    return 0;
}
