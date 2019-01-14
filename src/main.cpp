#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

#include "kit/ui/Theme.hpp"
#include "kit/ui/Texts.hpp"
#include "kit/ui/Icons.hpp"
#include "kit/ui/Buttons.hpp"

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

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
    theme = new Theme(primaryThemeColor, secondaryThemeColor);
    auto *texts = new Texts;
    auto *icons = new Icons;
    auto *buttons = new Buttons(theme);
    TextData textData = texts->getTextData("abcdefghijklmnopqrstuvwxyz", H1);
    TextData textDataUp = texts->getTextData("ABCDEFGHIJKLMNOPQRSTUVWXYZ", H1);

    while (1) {

        vita2d_start_drawing();
        vita2d_clear_screen();

        vita2d_draw_rectangle(0, 0, textData.width, textData.height, theme->getSecondaryRGBA().normal);
        vita2d_draw_rectangle(0, 300, textDataUp.width, textDataUp.height, theme->getSecondaryRGBA().normal);
        texts->draw("abcdefghijklmnopqrstuvwxyz", 0, 0, H1, theme->getPrimaryRGBA().text);
        texts->draw("ABCĘEFGHIJKLMNOPQRSTUVWXYZ", 0, 300, H1, theme->getPrimaryRGBA().text);


        /*texts->draw("test", 0, 140, H3, theme->getPrimaryRGBA().text);
        texts->draw("test", 0, 210, H4, theme->getPrimaryRGBA().text);
        texts->draw("test", 0, 280, H5, theme->getPrimaryRGBA().text);
        texts->draw("test", 0, 350, H6, theme->getPrimaryRGBA().text);

        texts->draw("test", 480, 0, H1, theme->getPrimaryRGBA().text, true);
        texts->draw("test", 480, 70, H2, theme->getPrimaryRGBA().text, true);
        texts->draw("test", 480, 140, H3, theme->getPrimaryRGBA().text, true);
        texts->draw("test", 480, 210, H4, theme->getPrimaryRGBA().text, true);
        texts->draw("test", 480, 280, H5, theme->getPrimaryRGBA().text, true);
        texts->draw("test", 480, 350, H6, theme->getPrimaryRGBA().text, true);*/

        /*icons->draw(ICON_MDI_APPLE, 0, 0);
        icons->draw(ICON_MDI_MICROSOFT, 50, 0);
        icons->draw(ICON_MDI_GOOGLE, 100, 0);*/

        //buttons->textDraw("test", 0, 0, ICON_MDI_PLUS);

        //buttons->textDraw("Apple", 480, 0, ICON_MDI_APPLE);

        //buttons->containedDraw("Test", 0, 0);


        vita2d_end_drawing();
        vita2d_swap_buffers();

    }

    vita2d_fini();

    sceKernelExitProcess(0);
    return 0;
}
