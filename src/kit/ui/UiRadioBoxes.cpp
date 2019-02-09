
#include "UiRadioBoxes.hh"
#include "UiCheckboxes.hh"

UiRadioBoxes::UiRadioBoxes(UiTheme *theme) : UiParentBoxes(theme) {}
UiRadioBoxes::UiRadioBoxes(UiTheme *theme, UiIcons *icons) : UiParentBoxes(theme, icons) {}
UiRadioBoxes::UiRadioBoxes(UiTheme *theme, UiIcons *icons, UiTexts *texts) : UiParentBoxes(theme, icons,
                                                                                                    texts) {}

ZoneEventRadioBoxes UiRadioBoxes::draw(int x, int y, UiRadioBoxesStatus status, bool selector, unsigned int size) {
    return this->drawWithText(x, y, status, "", selector, size);
}

ZoneEventRadioBoxes UiRadioBoxes::drawWithText(int x, int y, UiRadioBoxesStatus status, std::string text, bool selector, unsigned int size) {
    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.width = size * 2;
    zoneEvent.height = size * 2;
    zoneEvent.selector = selector;
    zoneEvent.status = status;

    this->drawSelector(x, y, selector);

    if (status == RADIOBOX_CHECKED) {
        this->drawBoxButtonColor(x, y, ICON_MDI_RADIOBOX_BLANK, (unsigned int) RGBA8(92, 92, 92, 255), size);
    }
    else {
        //this->drawBoxButtonColor(x, y, ICON_MDI_CHECKBOX_BLANK, (unsigned int) RGBA8(255, 255, 255, 255), size);
        this->drawBoxButton(x, y, ICON_MDI_RADIOBOX_MARKED, size);
    }

    if (!text.empty()) {
        zoneEvent.width += this->drawText(x, y , size, text).width;
    }


    return zoneEvent;
}


UiRadioBoxesStatus UiRadioBoxes::onPadAuto(ZoneEventRadioBoxes zoneEvent, bool button) {
    if (UiEvent::onPad(zoneEvent, button)) {
        if (zoneEvent.status == RADIOBOX_UNCHECKED) {
            return RADIOBOX_CHECKED;
        }
        else {
            return RADIOBOX_UNCHECKED;
        }
    }
    return zoneEvent.status;
}

UiRadioBoxesStatus UiRadioBoxes::onTouchAuto(ZoneEventRadioBoxes zoneEvent, SceIVector2 touchInfo) {
    if (UiEvent::onTouch(zoneEvent, touchInfo)) {
        if (zoneEvent.status == RADIOBOX_UNCHECKED) {
            return RADIOBOX_CHECKED;
        }
        else {
            return RADIOBOX_UNCHECKED;
        }
    }
    return zoneEvent.status;
}



