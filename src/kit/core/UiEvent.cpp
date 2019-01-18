#include "UiEvent.hh"

bool UiEvent::onPad(bool selector, bool button) {
    return selector && button;
}

bool UiEvent::onTouch(TouchZoneEvent tZ, vector2 touchInfo) {
    return (touchInfo.x > tZ.x && touchInfo.y > tZ.y && touchInfo.x < tZ.x + tZ.width && touchInfo.y < tZ.y + tZ.height);
}
