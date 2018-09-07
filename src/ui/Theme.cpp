#include "Theme.hpp"

Theme::Theme() = default;

Theme::Theme(const colorSchemeHEX &primary, const colorSchemeHEX &secondary) {

    this->primaryHEX = primary;
    this->secondaryHEX = secondary;

    this->primaryRGBA = this->colorSchemeHEXToColorShemeRGBA(this->primaryHEX);
    this->secondaryRGBA = this->colorSchemeHEXToColorShemeRGBA(this->secondaryHEX);

}

int Theme::convertHexToRGBA(char *hex) {
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    return RGBA8(r, g, b, 255);
}

colorSchemeRGBA Theme::colorSchemeHEXToColorShemeRGBA(colorSchemeHEX hex) {
    colorSchemeRGBA rgba;

    rgba.normal = this->convertHexToRGBA(hex.normal);
    rgba.dark = this->convertHexToRGBA(hex.dark);
    rgba.light = this->convertHexToRGBA(hex.light);
    rgba.text = this->convertHexToRGBA(hex.text);

    return rgba;
}

const colorSchemeHEX &Theme::getPrimaryHEX() const {
    return primaryHEX;
}

const colorSchemeHEX &Theme::getSecondaryHEX() const {
    return secondaryHEX;
}

const colorSchemeRGBA &Theme::getPrimaryRGBA() const {
    return primaryRGBA;
}

const colorSchemeRGBA &Theme::getSecondaryRGBA() const {
    return secondaryRGBA;
}




