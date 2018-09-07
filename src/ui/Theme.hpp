//see https://material.io/tools/color/#!/
#ifndef VITA_MATERIAL_KIT_THEME_HPP
#define VITA_MATERIAL_KIT_THEME_HPP

#include <cstdio>
#include <vita2d.h>

typedef struct{
    char *normal;
    char *light;
    char *dark;
    char *text;
} colorSchemeHEX;

typedef struct{
    int normal;
    int light;
    int dark;
    int text;
} colorSchemeRGBA;

class Theme {
private:
    colorSchemeHEX primaryHEX;
    colorSchemeHEX secondaryHEX;
    colorSchemeRGBA primaryRGBA;
    colorSchemeRGBA secondaryRGBA;

    colorSchemeRGBA colorSchemeHEXToColorShemeRGBA(colorSchemeHEX hex);
    int convertHexToRGBA(char *hex);

public:
    Theme();
    Theme(const colorSchemeHEX &primary, const colorSchemeHEX &secondary);

    const colorSchemeHEX &getPrimaryHEX() const;

    const colorSchemeHEX &getSecondaryHEX() const;

    const colorSchemeRGBA &getPrimaryRGBA() const;

    const colorSchemeRGBA &getSecondaryRGBA() const;

};


#endif //VITA_MATERIAL_KIT_THEME_HPP
