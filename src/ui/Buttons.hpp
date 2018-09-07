#ifndef VITA_MATERIAL_KIT_BUTTON_HPP
#define VITA_MATERIAL_KIT_BUTTON_HPP

#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

#include "Theme.hpp"
#include "Icons.hpp"

class Buttons {
private:
    Touch touch;
    Pad pad;
    Theme theme;
    Icons *icons;
public:
    Buttons(const Touch &touch, const Pad &pad, const Theme &theme);

    void textDraw(int x, int y, char *text, bool dense = false);
    void textDraw(int x, int y, char *text, char* icon, bool dense = false);

    void raisedDraw(int x, int y, char *text, bool dense = false);
    void raisedDraw(int x, int y, char *text, char* icon, bool dense = false);

    void unlevelatedDraw(int x, int y, char *text, bool dense = false);
    void unlevelatedDraw(int x, int y, char *text, char* icon, bool dense = false);

    void outlinedDraw(int x, int y, char *text, bool dense = false);
    void outlinedDraw(int x, int y, char *text, char* icon, bool dense = false);

};


#endif //VITA_MATERIAL_KIT_BUTTON_HPP
