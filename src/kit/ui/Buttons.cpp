
#include "Buttons.hpp"

Buttons::Buttons(Touch *touch, Pad *pad, Theme *theme) {
    this->touch = &touch;
    this->pad = &pad;
    this->theme = &theme;
    this->icons = new Icons();
}

void Buttons::textDraw(int x, int y, char *text, bool dense) {

}

void Buttons::textDraw(int x, int y, char *text, char *icon, bool dense) {

}

void Buttons::raisedDraw(int x, int y, char *text, bool dense) {

}

void Buttons::raisedDraw(int x, int y, char *text, char *icon, bool dense) {

}

void Buttons::unlevelatedDraw(int x, int y, char *text, bool dense) {

}

void Buttons::unlevelatedDraw(int x, int y, char *text, char *icon, bool dense) {

}

void Buttons::outlinedDraw(int x, int y, char *text, bool dense) {

}

void Buttons::outlinedDraw(int x, int y, char *text, char *icon, bool dense) {

}




