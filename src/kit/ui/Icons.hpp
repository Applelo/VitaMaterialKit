
#ifndef VITA_MATERIAL_KIT_ICONS_HPP
#define VITA_MATERIAL_KIT_ICONS_HPP

#include <vita2d.h>
#include <string>

#include "IconsCodes.h"
#include <math.h>

#define DEFAULT_MATERIAL_ICON_COLOR (unsigned int) RGBA8(255, 255, 255, 255)
#define DEFAULT_MATERIAL_ICON_SIZE (unsigned int) 50
#define DEFAULT_MATERIAL_ICON_PATH "app0:assets/fonts/mdi/" FONT_ICON_FILE_NAME_MDI

class Icons {
    private:
        vita2d_font *font;
    public:
        Icons();
        Icons(const char *path);
        void draw(const char* iconCode, int x, int y, unsigned int color = DEFAULT_MATERIAL_ICON_COLOR, unsigned int size = DEFAULT_MATERIAL_ICON_SIZE);

};


#endif //VITA_MATERIAL_KIT_ICONS_HPP
