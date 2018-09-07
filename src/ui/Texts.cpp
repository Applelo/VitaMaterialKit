
#include "Texts.hpp"

void Texts::drawFinal(char *text, int x, int y, Fonts *fonts, TextStyle textStyle, unsigned int color, bool italic) {
    switch (textStyle) {
        case H1:
            vita2d_font_draw_text(fonts->getFont(italic ? "LightItalic" : "Light"), x, y, color, 96, text);
            break;
        case H2:
            vita2d_font_draw_text(fonts->getFont(italic ? "LightItalic" : "Light"), x, y, color, 60, text);
            break;
        case H3:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 48, text);
            break;
        case H4:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 34, text);
            break;
        case H5:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 24, text);
            break;
        case H6:
            vita2d_font_draw_text(fonts->getFont(italic ? "MediumItalic" : "Medium"), x, y, color, 20, text);
            break;
        case Sub1:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 16, text);
            break;
        case Sub2:
            vita2d_font_draw_text(fonts->getFont(italic ? "MediumItalic" : "Medium"), x, y, color, 14, text);
            break;
        case Body1:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 16, text);
            break;
        case Body2:
            vita2d_font_draw_text(fonts->getFont(italic ? "MediumItalic" : "Medium"), x, y, color, 14, text);
            break;
        case Button:
            vita2d_font_draw_text(fonts->getFont(italic ? "MediumItalic" : "Medium"), x, y, color, 14, this->uppercase(text));
            break;
        case Caption:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 12, text);
            break;
        case Overline:
            vita2d_font_draw_text(fonts->getFont(italic ? "RegularItalic" : "Regular"), x, y, color, 10, this->uppercase(text));
            break;
    }
}

void Texts::draw(char *text, int x, int y, Fonts *fonts, TextStyle textStyle, bool italic) {
    this->drawFinal(text, x, y, fonts, textStyle, DEFAULT_FONT_COLOR, italic);
}

void Texts::draw(char *text, int x, int y, Fonts *fonts, TextStyle textStyle, unsigned int color, bool italic) {
    this->drawFinal(text, x, y, fonts, textStyle, color, italic);
}

void Texts::draw(char *text, int x, int y, vita2d_font *font, unsigned int size) {
    vita2d_font_draw_text(font, x, y, DEFAULT_FONT_COLOR, size, text);
}

void Texts::draw(char *text, int x, int y, vita2d_font *font, unsigned int size, unsigned int color) {
    vita2d_font_draw_text(font, x, y, color, size, text);
}

char *Texts::uppercase(char *text) {
    while(*text++)
    {
        std::cout << toupper(*text);
    }

    return text;
}
