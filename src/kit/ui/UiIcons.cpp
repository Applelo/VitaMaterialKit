#include "UiIcons.hpp"

UiIcons::UiIcons() {
    font = vita2d_load_font_file(DEFAULT_MATERIAL_ICON_PATH);
}

void UiIcons::draw(const char* iconCode, int x, int y, unsigned int color, unsigned int size) {
    y = y + size - (int) floor(size * 0.12);
    vita2d_font_draw_text(font, x, y, color, size, iconCode);
}