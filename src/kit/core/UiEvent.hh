#ifndef VITAMATERIALKIT_UIEVENT_HH
#define VITAMATERIALKIT_UIEVENT_HH

class UiEvent {
protected:
    bool virtual onClick(bool selector, bool button);
    bool virtual onTouch(int x, int y, int width, int height);
};


#endif //VITAMATERIALKIT_UIEVENT_HH
