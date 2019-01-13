
#ifndef VITA_MATERIAL_KIT_ICONS_HPP
#define VITA_MATERIAL_KIT_ICONS_HPP

#include <vita2d.h>
#include <string>

#define DEFAULT_MATERIAL_ICON_COLOR RGBA8(255, 255, 255, 255)
#define DEFAULT_MATERIAL_ICON_SIZE 50
#define DEFAULT_MATERIAL_ICON_PATH "app0:assets/fonts/Roboto/Roboto-Regular.ttf"

class Icons {
    private:
        vita2d_font *font;
    public:
        Icons();
        Icons(const char *path);
        void draw(int x, int y, const char* iconCode);
        void draw(int x, int y, const char* iconCode, unsigned int color);
        void draw(int x, int y, const char* iconCode, unsigned int color, unsigned int size);

};


#endif //VITA_MATERIAL_KIT_ICONS_HPP
