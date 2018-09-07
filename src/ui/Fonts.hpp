
#ifndef VITA_MATERIAL_KIT_FONTS_HH
#define VITA_MATERIAL_KIT_FONTS_HH


#include <vita2d.h>
#include <map>

class Fonts {
private:
    std::map<std::string,  vita2d_font*> fonts;
public:
    Fonts();
    Fonts(std::string family);

    void init(std::string family);

    vita2d_font* getFont(std::string type);

    virtual ~Fonts();

};


#endif //VITA_MATERIAL_KIT_FONTS_HH
