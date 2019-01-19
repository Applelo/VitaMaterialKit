#include "kit/ui/UiIcons.hpp"

#include <psp2/kernel/processmgr.h>


int main() {

    auto *icons = new UiIcons();

    vita2d_init();
    vita2d_set_clear_color((unsigned int) RGBA8(218, 219, 219, 255));

    while (1) {
        vita2d_start_drawing();
        vita2d_clear_screen();


        icons->draw(ICON_MDI_FILE, 0,0);


        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();
    sceKernelExitProcess(0);

}
