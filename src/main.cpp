#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

#include "kit/ui/Theme.hpp"
#include "kit/ui/Texts.hpp"

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

    vita2d_pgf *pgf;
    Theme *theme;

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    theme = new Theme(primaryThemeColor, secondaryThemeColor);
    auto *texts = new Texts;

    while (1) {

        vita2d_start_drawing();
        vita2d_clear_screen();

       

        vita2d_end_drawing();
        vita2d_swap_buffers();

    }

    vita2d_fini();
    vita2d_free_pgf(pgf);

    sceKernelExitProcess(0);
    return 0;
}
