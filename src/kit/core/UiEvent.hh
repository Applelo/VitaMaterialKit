#ifndef VITAMATERIALKIT_UIEVENT_HH
#define VITAMATERIALKIT_UIEVENT_HH

#include "../utils/Touch.hpp"

typedef struct TouchZoneEvent {
    int x;
    int y;
    int width;
    int height;
} TouchZoneEvent;

class UiEvent {
protected:
    TouchZoneEvent touchZoneEvent;
public:
    bool onPad(bool selector, bool button);
    bool onTouch(TouchZoneEvent touchZoneEvent, vector2 touchInfo);
};


#endif //VITAMATERIALKIT_UIEVENT_HH
