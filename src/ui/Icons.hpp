
#ifndef VITA_MATERIAL_KIT_ICONS_HPP
#define VITA_MATERIAL_KIT_ICONS_HPP

#include <vita2d.h>
#include <string>

#define DEFAULT_FONT_COLOR RGBA8(255, 255, 255, 255)
#define DEFAULT_FONT_SIZE 50

class Icons {
    private:
        vita2d_font *font;
    public:
        Icons();
        void draw(int x, int y, const char* iconCode);
        void draw(int x, int y, const char* iconCode, unsigned int color);
        void draw(int x, int y, const char* iconCode, unsigned int color, unsigned int size);

};


#endif //VITA_MATERIAL_KIT_ICONS_HPP
