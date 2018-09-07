
#ifndef VITA_MATERIAL_KIT_TEXT_HPP
#define VITA_MATERIAL_KIT_TEXT_HPP


#include "Fonts.hpp"
#include <iostream>

#define DEFAULT_FONT_COLOR RGBA8(255, 255, 255, 255)

//see https://material.io/design/typography/the-type-system.html#type-scale
typedef enum TextStyle {
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    Sub1,
    Sub2,
    Body1,
    Body2,
    Button,
    Caption,
    Overline
} TextStyle;

class Texts {
private:
    char *uppercase(char *text);
    void drawFinal(char *text, int x, int y, Fonts *fonts, TextStyle textStyle, unsigned int color, bool italic);
public:
    void draw(char *text, int x, int y, Fonts *fonts, TextStyle textStyle, bool italic = false);
    void draw(char *text, int x, int y, Fonts *fonts, TextStyle textStyle, unsigned int color, bool italic = false);

    void draw(char *text, int x, int y, vita2d_font *font, unsigned int size);
    void draw(char *text, int x, int y, vita2d_font *font, unsigned int size, unsigned int color);


};


#endif //VITA_MATERIAL_KIT_TEXT_HPP
