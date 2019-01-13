

#include "Icons.hpp"

Icons::Icons() {
    font = vita2d_load_font_file(DEFAULT_MATERIAL_ICON_PATH);
}

Icons::Icons(const char *path) {
    font = vita2d_load_font_file(path);
}

void Icons::draw(int x, int y, const char* iconCode) {
    vita2d_font_draw_text(font, x, y, DEFAULT_MATERIAL_ICON_COLOR, DEFAULT_MATERIAL_ICON_SIZE, iconCode);
}

void Icons::draw(int x, int y, const char* iconCode, unsigned int color) {
    vita2d_font_draw_text(font, x, y, color, DEFAULT_MATERIAL_ICON_SIZE, iconCode);
}

void Icons::draw(int x, int y, const char* iconCode, unsigned int color, unsigned int size) {
    vita2d_font_draw_text(font, x, y, color, size, iconCode);
}