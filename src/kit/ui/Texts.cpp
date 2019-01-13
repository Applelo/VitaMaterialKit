#include <utility>

#include <algorithm>
#include "Texts.hpp"

Texts::Texts() {
    this->init("Roboto");
}

Texts::Texts(std::string family) {
    this->init(std::move(family));
}

Texts::~Texts() {
    for (const auto& kv : this->fonts) {
        vita2d_free_font(kv.second);
    }
}

void Texts::init(std::string family) {

    SceIoDirent gDir;
    std::string fontsPath = DEFAULT_FONTS_PATH;
    fontsPath = fontsPath + family;

    int fd = sceIoDopen(fontsPath.c_str());//open fonts folder

    std::string fontPath, fileName, fontName;

    fontsPath.append("/");//add slash for folder

    while (sceIoDread(fd, &gDir) > 0) {
        fileName = gDir.d_name;
        fontPath = fontsPath + fileName;//get the path of the file

        fontName = fileName.erase(0, family.length() + 1);//remove the family name and -
        fontName = fontName.erase(fontName.length() - 4, fontName.length());//remove .ttf
        fonts[fontName] = vita2d_load_font_file(fontPath.c_str());

    }

    sceIoClose(fd);
}

void Texts::drawFinal(std::string text, int x, int y, TextStyle textStyle, unsigned int color, bool italic) {
    switch (textStyle) {
        case H1:
            vita2d_font_draw_text(fonts[italic ? "LightItalic" : "Light"], x, y, color, 96, text.c_str());
            break;
        case H2:
            vita2d_font_draw_text(fonts[italic ? "LightItalic" : "Light"], x, y, color, 60, text.c_str());
            break;
        case H3:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 48, text.c_str());
            break;
        case H4:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 34, text.c_str());
            break;
        case H5:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 24, text.c_str());
            break;
        case H6:
            vita2d_font_draw_text(fonts[italic ? "MediumItalic" : "Medium"], x, y, color, 20, text.c_str());
            break;
        case Sub1:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 16, text.c_str());
            break;
        case Sub2:
            vita2d_font_draw_text(fonts[italic ? "MediumItalic" : "Medium"], x, y, color, 14, text.c_str());
            break;
        case Body1:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 16, text.c_str());
            break;
        case Body2:
            vita2d_font_draw_text(fonts[italic ? "MediumItalic" : "Medium"], x, y, color, 14, text.c_str());
            break;
        case Button:
            vita2d_font_draw_text(fonts[italic ? "MediumItalic" : "Medium"], x, y, color, 14, this->uppercase(text).c_str());
            break;
        case Caption:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 12, text.c_str());
            break;
        case Overline:
            vita2d_font_draw_text(fonts[italic ? "RegularItalic" : "Regular"], x, y, color, 10, this->uppercase(text).c_str());
            break;
    }
}

//Draw with Material Style
void Texts::draw(std::string text, int x, int y, TextStyle textStyle, bool italic) {
    this->drawFinal(std::move(text), x, y, textStyle, DEFAULT_FONT_COLOR, italic);
}

void Texts::draw(std::string text, int x, int y, TextStyle textStyle, unsigned int color, bool italic) {
    this->drawFinal(std::move(text), x, y, textStyle, color, italic);
}

//Draw with selected font type
void Texts::draw(std::string text, int x, int y, char *fontType, unsigned int size, bool uppercase) {
    vita2d_font_draw_text(fonts[fontType], x, y, DEFAULT_FONT_COLOR, size, uppercase ? this->uppercase(text).c_str() : text.c_str());
}

void Texts::draw(std::string text, int x, int y, char *fontType, unsigned int size, unsigned int color, bool uppercase) {
    vita2d_font_draw_text(fonts[fontType], x, y, color, size, uppercase ? this->uppercase(text).c_str() : text.c_str());
}


//Draw with chosen font
void Texts::draw(std::string text, int x, int y, vita2d_font *font, unsigned int size, bool uppercase) {
    vita2d_font_draw_text(font, x, y, DEFAULT_FONT_COLOR, size, uppercase ? this->uppercase(text).c_str() : text.c_str());
}

void Texts::draw(std::string text, int x, int y, vita2d_font *font, unsigned int size, unsigned int color, bool uppercase) {
    vita2d_font_draw_text(font, x, y, color, size, uppercase ? this->uppercase(text).c_str() : text.c_str());
}

//set text to uppercase
std::string Texts::uppercase(std::string text) {
    std::transform(text.begin(), text.end(),text.begin(), ::toupper);
    return text;
}
