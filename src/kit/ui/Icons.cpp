#include "Icons.hpp"

Icons::Icons() {
    font = vita2d_load_font_file(DEFAULT_MATERIAL_ICON_PATH);
}

Icons::Icons(const char *path) {
    font = vita2d_load_font_file(path);
}

void Icons::draw(const char* iconCode, int x, int y, unsigned int color, unsigned int size) {
    y = y + size - (int) floor(size * 0.12);
    vita2d_font_draw_text(font, x, y, color, size, iconCode);
}