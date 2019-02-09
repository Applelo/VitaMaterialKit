#ifndef VITAMATERIALKIT_UICHECKBOXES_HH
#define VITAMATERIALKIT_UICHECKBOXES_HH


#include "UiTheme.hpp"
#include "UiIcons.hpp"
#include "../core/UiEvent.hh"
#include "parent/UiParentBoxButtons.hh"

#define DEFAULT_CHECKBOX_SIZE 40

typedef enum UiCheckboxesStatus {
    UNCHECKED = 0,
    INDERTERMINATE = -1,
    CHECKED = 1
} UiCheckboxesStatus;

typedef struct ZoneEventCheckboxes : public ZoneEvent {
    UiCheckboxesStatus status;
} ZoneEventCheckboxes;

class UiCheckboxes : public UiEvent, UiParentBoxButtons {
private:
    ZoneEventCheckboxes zoneEvent;
public:
    UiCheckboxes(UiTheme *theme);
    UiCheckboxes(UiTheme *theme, UiIcons *icons);
    UiCheckboxes(UiTheme *theme, UiIcons *icons, UiTexts *texts);

    ZoneEventCheckboxes draw(int x, int y, UiCheckboxesStatus status, bool selector, unsigned int size = DEFAULT_CHECKBOX_SIZE);
    ZoneEventCheckboxes drawWithText(int x, int y, UiCheckboxesStatus status, std::string text, bool selector, unsigned int size = DEFAULT_CHECKBOX_SIZE);

    UiCheckboxesStatus onPadAuto(ZoneEventCheckboxes zoneEvent, bool button);
    UiCheckboxesStatus onTouchAuto(ZoneEventCheckboxes zoneEvent, SceIVector2 touchInfo);
};


#endif //VITAMATERIALKIT_UICHECKBOXES_HH
