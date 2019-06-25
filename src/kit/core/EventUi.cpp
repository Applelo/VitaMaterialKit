#include "EventUi.hh"

bool EventUi::onPad(ZoneEvent zoneEvent, bool button) {
    return zoneEvent.selector && button;
}

bool EventUi::onTouch(ZoneEvent zE, SceIVector2 touchInfo) {
    return (touchInfo.x > zE.x && touchInfo.y > zE.y && touchInfo.x < zE.x + zE.width && touchInfo.y < zE.y + zE.height);
}

bool EventUi::on(ZoneEvent zoneEvent, bool button) {
    return EventUi::onPad(zoneEvent, button);
}

bool EventUi::on(ZoneEvent zoneEvent, SceIVector2 touchInfo) {
    return EventUi::onTouch(zoneEvent, touchInfo);
}

bool EventUi::on(ZoneEvent zoneEvent, SceIVector2 touchInfo, bool button, bool isTouch) {
    if (isTouch) {
        return EventUi::onTouch(zoneEvent, touchInfo);
    }
    else {
        return EventUi::onPad(zoneEvent, button);
    }
}
