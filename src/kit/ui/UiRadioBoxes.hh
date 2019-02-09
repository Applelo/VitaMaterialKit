#ifndef VITAMATERIALKIT_UIRADIOBOXES_HH
#define VITAMATERIALKIT_UIRADIOBOXES_HH

#include "../core/UiEvent.hh"
#include "parent/UiParentBoxes.hh"

typedef enum UiRadioBoxesStatus {
    RADIOBOX_UNCHECKED = 0,
    RADIOBOX_CHECKED = 1
} UiRadioBoxesStatus;


typedef struct ZoneEventRadioBoxes : public ZoneEvent {
    UiRadioBoxesStatus status;
} ZoneEventRadioBoxes;

class UiRadioBoxes : public ZoneEvent, UiParentBoxes {
private:
    ZoneEventRadioBoxes zoneEvent;
public:
    UiRadioBoxes(UiTheme *theme);
    UiRadioBoxes(UiTheme *theme, UiIcons *icons);
    UiRadioBoxes(UiTheme *theme, UiIcons *icons, UiTexts *texts);

    ZoneEventRadioBoxes draw(int x, int y, UiRadioBoxesStatus status, bool selector, unsigned int size = BOXES_DEFAULT_SIZE);
    ZoneEventRadioBoxes drawWithText(int x, int y, UiRadioBoxesStatus status, std::string text, bool selector, unsigned int size = BOXES_DEFAULT_SIZE);

    UiRadioBoxesStatus onPadAuto(ZoneEventRadioBoxes zoneEvent, bool button);
    UiRadioBoxesStatus onTouchAuto(ZoneEventRadioBoxes zoneEvent, SceIVector2 touchInfo);

};


#endif //VITAMATERIALKIT_UIRADIOBOXES_HH
