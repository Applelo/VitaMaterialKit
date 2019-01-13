
#ifndef VITA_MATERIAL_KIT_TEXT_HPP
#define VITA_MATERIAL_KIT_TEXT_HPP


#include <map>
#include <iostream>

#include <psp2/io/fcntl.h>
#include <psp2/io/dirent.h>

#include "vita2d.h"

#define DEFAULT_FONT_COLOR RGBA8(255, 255, 255, 255)
#define DEFAULT_FONTS_PATH "app0:assets/fonts/"

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
    std::map<std::string, vita2d_font*> fonts;
    const char *type;
    int height;
    unsigned int size;


    std::string uppercase(std::string text);
    void drawFinal(std::string text, int x, int y, TextStyle textStyle, unsigned int color, bool italic);
public:
    Texts();
    explicit Texts(std::string family);

    ~Texts();

    void init(std::string family);

    void draw(std::string text, int x, int y, TextStyle textStyle, bool italic = false);
    void draw(std::string text, int x, int y, TextStyle textStyle, unsigned int color, bool italic = false);

    void draw(std::string text, int x, int y, char *fontType, unsigned int size, bool uppercase = false);
    void draw(std::string text, int x, int y, char *fontType, unsigned int size, unsigned int color, bool uppercase = false);

    void draw(std::string text, int x, int y, vita2d_font *font, unsigned int size, bool uppercase = false);
    void draw(std::string text, int x, int y, vita2d_font *font, unsigned int size, unsigned int color, bool uppercase = false);

};


#endif //VITA_MATERIAL_KIT_TEXT_HPP
