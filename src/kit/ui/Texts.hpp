#ifndef VITA_MATERIAL_KIT_TEXT_HPP
#define VITA_MATERIAL_KIT_TEXT_HPP


#include <map>
#include <iostream>
#include <math.h>
#include <algorithm>

#include <psp2/io/fcntl.h>
#include <psp2/io/dirent.h>

#include "vita2d.h"


#define DEFAULT_FONT_COLOR RGBA8(255, 255, 255, 255)
#define DEFAULT_FONTS_PATH "app0:assets/fonts/"
#define DEFAULT_SIZE_OFFSET 12

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


typedef struct TextStyleData {
    const char *type;
    unsigned int size;
    bool uppercase;
    double offset;
} TextStyleData;

typedef struct TextData {
    int width;
    int height;

} TextData;

class Texts {
private:
    std::map<std::string, vita2d_font*> fonts;
    TextData textData;
    TextStyleData textStyleData;

    const char * toUppercase(const char *text);
    void drawFinal(int x, int y, TextStyle textStyle, unsigned int color, bool italic, const char *text);
    void drawFinal(int x, int y, TextStyleData _textStyleData, unsigned int color, const char *text);

    void calcTextStyleData(TextStyle textStyle, bool italic = false);
    void calcTextData(const char *text, TextStyle textStyle, bool italic = false);
public:
    Texts();
    Texts(const char *family);

    ~Texts();

    void init(std::string family);

    //Material Style
    void draw(int x, int y, TextStyle textStyle, const char *text);
    void draw(int x, int y, TextStyle textStyle, unsigned int color, const char *text);
    void draw(int x, int y, TextStyle textStyle, unsigned int color, bool italic, const char *text);

    void drawF(int x, int y, TextStyle textStyle, unsigned int color, bool italic, const char *text, ...);

    //Do with your style
    void draw(int x, int y, TextStyleData _textStyleData, const char *text);
    void draw(int x, int y, TextStyleData _textStyleData, unsigned int color, const char *text);

    void drawF(int x, int y, TextStyleData _textStyleData, unsigned int color, const char *text, ...);


    TextData getTextData(const char *text, TextStyle textStyle, bool italic = false);

};


#endif //VITA_MATERIAL_KIT_TEXT_HPP
