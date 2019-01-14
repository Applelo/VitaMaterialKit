#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

#include "kit/ui/Theme.hpp"
#include "kit/ui/Texts.hpp"
#include "kit/ui/Icons.hpp"
#include "kit/ui/Buttons.hpp"

#include "kit/utils/I18n.hpp"
#include "kit/utils/IME.hpp"

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

    auto *currentLang = new I18n();
    auto *frLang = new I18n(SCE_SYSTEM_PARAM_LANG_FRENCH);
    auto *enLang = new I18n(SCE_SYSTEM_PARAM_LANG_ENGLISH_US);
    IME *ime = new IME();

    while (1) {

        vita2d_start_drawing();
        vita2d_clear_screen();

        ime->getUserText((char*)"Edit message" , "", SCE_IME_TYPE_NUMBER);

        //icons->draw(ICON_MDI_APPLE, 0, 0);
        //icons->draw(ICON_MDI_ACCOUNT_KEY, 0, 0);
        //icons->draw(ICON_MDI_MICROSOFT, 0, 0);

        /*buttons->textDraw("Text", 50, 0);
        buttons->textDraw("Text & Icon", 300, 0, ICON_MDI_ACCOUNT);

        buttons->containedDraw("Contained", 50, 150);
        buttons->containedDraw("Contained & Icon", 300, 150, ICON_MDI_ACCOUNT);

        buttons->outlinedDraw("Outlined", 50, 300);
        buttons->outlinedDraw("Outlined & Icon", 300, 300, ICON_MDI_ACCOUNT);

        buttons->floatDraw(ICON_MDI_PLUS, 50, 450);
        buttons->floatDraw(ICON_MDI_PLUS, 300, 450, "Extended Float");*/

        /*texts->draw(0, 140, Body1, theme->getPrimaryRGBA().text, currentLang->getI18nByCat("test")["phrase"]);
        texts->draw(0, 210, Body1, theme->getPrimaryRGBA().text, frLang->getI18nByCat("test")["phrase"]);
        texts->draw(0, 280, Body1, theme->getPrimaryRGBA().text, enLang->getI18nByCat("test")["phrase"]);*/



        vita2d_end_drawing();
        vita2d_swap_buffers();

    }

    vita2d_fini();

    sceKernelExitProcess(0);
    return 0;
}
