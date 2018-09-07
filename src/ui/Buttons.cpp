
#include "Buttons.hpp"

Buttons::Buttons(const Touch &touch, const Pad &pad, const Theme &theme) : touch(touch), pad(pad), theme(theme) {
    this->touch = touch;
    this->pad = pad;
    this->theme = theme;
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




