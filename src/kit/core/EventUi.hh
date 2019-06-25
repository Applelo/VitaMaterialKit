#ifndef VITAMATERIALKIT_EVENTUI_HH
#define VITAMATERIALKIT_EVENTUI_HH

#include "../utils/UtilsTouch.hh"

typedef struct ZoneEvent {
    int x;
    int y;
    int width;
    int height;
    bool selector;
} ZoneEvent;

class EventUi {
public:
    static bool on(ZoneEvent zoneEvent, bool button);
    static bool on(ZoneEvent zoneEvent, SceIVector2 touchInfo);
    static bool on(ZoneEvent zoneEvent, SceIVector2 touchInfo, bool button, bool isTouch);
    static bool onPad(ZoneEvent zoneEvent, bool button);
    static bool onTouch(ZoneEvent zoneEvent, SceIVector2 touchInfo);
};


#endif //VITAMATERIALKIT_EVENTUI_HH
