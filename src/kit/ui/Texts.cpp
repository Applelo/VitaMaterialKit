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

    this->calcTextData(text, textStyle, italic);

    vita2d_font_draw_text(fonts[textStyleData.type], x, y + textData.height, color, textStyleData.size, textStyleData.uppercase ? this->toUppercase(text).c_str() : text.c_str());
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
    vita2d_font_draw_text(fonts[fontType], x, y, DEFAULT_FONT_COLOR, size, uppercase ? this->toUppercase(text).c_str() : text.c_str());
}

void Texts::draw(std::string text, int x, int y, char *fontType, unsigned int size, unsigned int color, bool uppercase) {
    vita2d_font_draw_text(fonts[fontType], x, y, color, size, uppercase ? this->toUppercase(text).c_str() : text.c_str());
}


//Draw with chosen font
void Texts::draw(std::string text, int x, int y, vita2d_font *font, unsigned int size, bool uppercase) {
    vita2d_font_draw_text(font, x, y, DEFAULT_FONT_COLOR, size, uppercase ? this->toUppercase(text).c_str() : text.c_str());
}

void Texts::draw(std::string text, int x, int y, vita2d_font *font, unsigned int size, unsigned int color, bool uppercase) {
    vita2d_font_draw_text(font, x, y, color, size, uppercase ? this->toUppercase(text).c_str() : text.c_str());
}

TextData Texts::getTextData(std::string text, TextStyle textStyle, bool italic) {
    this->calcTextData(text, textStyle, italic);

    return textData;
}

//private

//set text to uppercase
std::string Texts::toUppercase(std::string text) {
    std::transform(text.begin(), text.end(),text.begin(), ::toupper);
    return text;
}

void Texts::calcTextData(std::string text, TextStyle textStyle, bool italic) {

    this->calcTextStyleData(textStyle, italic);

    textData.width = vita2d_font_text_width(fonts[textStyleData.type], textStyleData.size, textStyleData.uppercase ? this->toUppercase(text).c_str() : text.c_str());
    textData.height = vita2d_font_text_height(fonts[textStyleData.type], textStyleData.size, textStyleData.uppercase ? this->toUppercase(text).c_str() : text.c_str());
}

void Texts::calcTextStyleData(TextStyle textStyle, bool italic) {

    textStyleData.type = "Regular";
    textStyleData.size = 16;
    textStyleData.uppercase = false;

    switch (textStyle) {
        case H1:
            textStyleData.type = italic ? "LightItalic" : "Light";
            textStyleData.size = 96;
            break;
        case H2:
            textStyleData.type = italic ? "LightItalic" : "Light";
            textStyleData.size = 60;
            break;
        case H3:
            textStyleData.type = italic ? "Italic" : "Regular";
            textStyleData.size = 48;
            break;
        case H4:
            textStyleData.type = italic ? "Italic" : "Regular";
            textStyleData.size = 34;
            break;
        case H5:
            textStyleData.type = italic ? "Italic" : "Regular";
            textStyleData.size = 24;
            break;
        case H6:
            textStyleData.type = italic ? "MediumItalic" : "Medium";
            textStyleData.size = 20;
            break;
        case Sub1:
        case Body1:
            textStyleData.type = italic ? "Italic" : "Regular";
            textStyleData.size = 16;
            break;
        case Sub2:
        case Body2:
            textStyleData.type = italic ? "MediumItalic" : "Medium";
            textStyleData.size = 14;
            break;
        case Button:
            textStyleData.type = italic ? "MediumItalic" : "Medium";
            textStyleData.size = 26;//normalement 14
            textStyleData.uppercase = true;
            break;
        case Caption:
            textStyleData.type = italic ? "Italic" : "Regular";
            textStyleData.size = 12;
            break;
        case Overline:
            textStyleData.type = italic ? "Italic" : "Regular";
            textStyleData.size = 10;
            textStyleData.uppercase = true;
            break;

    }
}
