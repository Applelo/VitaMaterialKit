#include "UiTexts.hpp"

UiTexts::UiTexts() {
    this->init("Roboto");
}

UiTexts::UiTexts(const char *family) {
    this->init(family);
}

UiTexts::~UiTexts() {
    for (const auto& kv : this->fonts) {
        vita2d_free_font(kv.second);
    }
}

void UiTexts::init(std::string family) {
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

void UiTexts::drawFinal(int x, int y, TextStyle textStyle, unsigned int color, bool italic, const char *text) {
    this->calcTextStyleData(textStyle, italic);

    vita2d_font_draw_text(fonts[textStyleData.type], x, (int) floor(y + textStyleData.size - textStyleData.offset), color, textStyleData.size, textStyleData.uppercase ? this->toUppercase(text) : text);
}

void UiTexts::drawFinal(int x, int y, TextStyleData _textStyleData, unsigned int color,  const char *text) {
    vita2d_font_draw_text(fonts[_textStyleData.type], x, (int) floor(y + _textStyleData.size - _textStyleData.offset), color, _textStyleData.size, _textStyleData.uppercase ? this->toUppercase(text) : text);
}

//Draw with Material Style
void UiTexts::draw(int x, int y, TextStyle textStyle,  const char *text) {
    this->drawFinal(x, y, textStyle, (unsigned int)DEFAULT_FONT_COLOR, false, text);
}

void UiTexts::draw(int x, int y, TextStyle textStyle, unsigned int color,  const char *text) {
    this->drawFinal(x, y, textStyle, color, false, text);
}

void UiTexts::draw(int x, int y, TextStyle textStyle, unsigned int color, bool italic,  const char *text) {
    this->drawFinal(x, y, textStyle, color, italic, text);
}

void UiTexts::drawF(int x, int y, TextStyle textStyle, unsigned int color, bool italic, const char *text, ...) {
    char buf[1024];
    va_list argPtr;

    va_start(argPtr, text);
    vsnprintf(buf, sizeof(buf), text, argPtr);
    va_end(argPtr);

    this->drawFinal(x, y, textStyle, color, italic, buf);
}

//Draw with your style
void UiTexts::draw(int x, int y, TextStyleData _textStyleData, const char *text) {
    this->drawFinal(x, y, _textStyleData, (unsigned int)DEFAULT_FONT_COLOR, text);
}

void UiTexts::draw(int x, int y, TextStyleData _textStyleData, unsigned int color, const char *text) {
    this->drawFinal(x, y, _textStyleData, color, text);
}

void UiTexts::drawF(int x, int y, TextStyleData _textStyleData, unsigned int color, const char *text, ...) {
    char buf[1024];
    va_list argPtr;

    va_start(argPtr, text);
    vsnprintf(buf, sizeof(buf), text, argPtr);
    va_end(argPtr);

    this->drawFinal(x, y, _textStyleData, color, buf);
}


//utils
TextData UiTexts::getTextData(const char * text, TextStyle textStyle, bool italic) {
    this->calcTextData(text, textStyle, italic);
    return textData;
}

TextData UiTexts::getTextData(const char *text, TextStyleData _textStyleData) {
    textData.width = vita2d_font_text_width(fonts[_textStyleData.type], _textStyleData.size, _textStyleData.uppercase ? this->toUppercase(text) : text);
    textData.height = vita2d_font_text_height(fonts[_textStyleData.type], _textStyleData.size, _textStyleData.uppercase ? this->toUppercase(text) : text);

    return textData;
}

//private

//set text to uppercase
const char *UiTexts::toUppercase(const char *text) {
    char* textUp = (char *)text;

    for(char* c=textUp; (*c = (char)toupper(*c)); ++c) ;

    return text;
}

void UiTexts::calcTextData(const char *text, TextStyle textStyle, bool italic) {

    this->calcTextStyleData(textStyle, italic);

    textData.width = vita2d_font_text_width(fonts[textStyleData.type], textStyleData.size, textStyleData.uppercase ? this->toUppercase(text) : text);
    textData.height = vita2d_font_text_height(fonts[textStyleData.type], textStyleData.size, textStyleData.uppercase ? this->toUppercase(text) : text);
}


void UiTexts::calcTextStyleData(TextStyle textStyle, bool italic) {

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
            textStyleData.size = 14;
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
    textStyleData.size += DEFAULT_SIZE_OFFSET;

    textStyleData.offset = textStyleData.size * 0.24;//correct font position
}

