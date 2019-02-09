#include "UiCheckboxes.hh"

UiCheckboxes::UiCheckboxes(UiTheme *theme) : UiParentBoxes(theme) {}
UiCheckboxes::UiCheckboxes(UiTheme *theme, UiIcons *icons) : UiParentBoxes(theme, icons) {}
UiCheckboxes::UiCheckboxes(UiTheme *theme, UiIcons *icons, UiTexts *texts) : UiParentBoxes(theme, icons, texts) {}

ZoneEventCheckboxes UiCheckboxes::draw(int x, int y, UiCheckboxesStatus status, bool selector, unsigned int size) {
    return this->drawWithText(x, y, status, "", selector, size);
}

ZoneEventCheckboxes UiCheckboxes::drawWithText(int x, int y, UiCheckboxesStatus status, std::string text, bool selector,
                                               unsigned int size) {
    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.width = size * 2;
    zoneEvent.height = size * 2;
    zoneEvent.selector = selector;
    zoneEvent.status = status;

    this->drawSelector(x, y, selector);

    if (status == CHECKBOX_INDERTERMINATE || status == CHECKBOX_CHECKED) {
        this->drawBoxButtonColor(x, y, ICON_MDI_CHECKBOX_BLANK, (unsigned int) RGBA8(255, 255, 255, 255), size);
    }

    if (status == CHECKBOX_UNCHECKED) {
        this->drawBoxButtonColor(x, y, ICON_MDI_CHECKBOX_BLANK_OUTLINE, (unsigned int) RGBA8(92, 92, 92, 255), size);
    }
    else if (status == CHECKBOX_INDERTERMINATE) {
        this->drawBoxButton(x, y, ICON_MDI_MINUS_BOX, size);
    }
    else {
        this->drawBoxButton(x, y, ICON_MDI_CHECKBOX_MARKED, size);
    }

    if (!text.empty()) {
        zoneEvent.width += this->drawText(x, y , size, text).width;
    }


    return zoneEvent;
}


UiCheckboxesStatus UiCheckboxes::onPadAuto(ZoneEventCheckboxes zoneEvent, bool button) {
    if (UiEvent::onPad(zoneEvent, button)) {
        if (zoneEvent.status == CHECKBOX_UNCHECKED || zoneEvent.status == CHECKBOX_INDERTERMINATE) {
            return CHECKBOX_CHECKED;
        }
        else {
            return CHECKBOX_UNCHECKED;
        }
    }
    return zoneEvent.status;
}

UiCheckboxesStatus UiCheckboxes::onTouchAuto(ZoneEventCheckboxes zoneEvent, SceIVector2 touchInfo) {
    if (UiEvent::onTouch(zoneEvent, touchInfo)) {
        if (zoneEvent.status == CHECKBOX_UNCHECKED || zoneEvent.status == CHECKBOX_INDERTERMINATE) {
            return CHECKBOX_CHECKED;
        }
        else {
            return CHECKBOX_UNCHECKED;
        }
    }
    return zoneEvent.status;
}



