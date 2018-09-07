#include <utility>


#include <vitasdk.h>
#include "Fonts.hpp"

Fonts::Fonts() {
    this->init("Roboto");
}

Fonts::Fonts(std::string family) {
    this->init(std::move(family));
}

Fonts::~Fonts() {
    for (const auto& kv : this->fonts) {
        vita2d_free_font(kv.second);
    }
}

void Fonts::init(std::string family) {
    SceIoDirent gDir;
    std::string fontsPath = "app0:assets/fonts/";
    fontsPath = fontsPath + family;

    int fd = sceIoDopen(fontsPath.c_str());//open fonts folder

    std::string fontPath, fileName, fontName;
    fontsPath.append("/");//add slash for folder

    while (sceIoDread(fd, &gDir) > 0) {
        fileName = gDir.d_name;
        fontPath = fontsPath + fileName;//get the path of the file
        fontName = fileName.substr(0, family.length());//remove the family name
        fontName = fontName.substr(fontName.length() - 5, fontName.length() - 1);//remove .ttf
        this->fonts.insert(std::pair<std::string,  vita2d_font*>(fontName, vita2d_load_font_file(fontPath.c_str())));
    }

    sceIoClose(fd);
}

vita2d_font *Fonts::getFont(std::string type) {
    return this->fonts[type];
}