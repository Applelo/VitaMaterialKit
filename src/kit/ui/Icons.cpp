#include "Icons.hpp"

Icons::Icons() {
    font = vita2d_load_font_file(DEFAULT_MATERIAL_ICON_PATH);
}

Icons::Icons(const char *path) {
    font = vita2d_load_font_file(path);
}

void Icons::draw(const char* iconCode, int x, int y) {
    heigth = vita2d_font_text_height(font, DEFAULT_MATERIAL_ICON_SIZE, iconCode);
    vita2d_font_draw_text(font, x, y + heigth, DEFAULT_MATERIAL_ICON_COLOR, DEFAULT_MATERIAL_ICON_SIZE, iconCode);
}

void Icons::draw(const char* iconCode, int x, int y, unsigned int color) {
    heigth = vita2d_font_text_height(font, DEFAULT_MATERIAL_ICON_SIZE, iconCode);
    vita2d_font_draw_text(font, x, y + heigth, color, DEFAULT_MATERIAL_ICON_SIZE, iconCode);
}

void Icons::draw(const char* iconCode, int x, int y, unsigned int color, unsigned int size) {
    heigth = vita2d_font_text_height(font, size, iconCode);
    vita2d_font_draw_text(font, x, y + heigth, color, size, iconCode);
}