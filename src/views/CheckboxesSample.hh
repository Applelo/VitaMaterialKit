//
// Created by Loïs Boubault on 2019-01-22.
//

#ifndef VITAMATERIALKIT_CHECKBOXESSAMPLE_HH
#define VITAMATERIALKIT_CHECKBOXESSAMPLE_HH


#include "../kit/core/View.hh"

#define NUMBER_OF_BUTTONS_CHECKBOXES 4

class CheckboxesSample : public View {
private:
    int selector = -1;
    ZoneEvent back;
    ZoneEventCheckboxes uncheckedZE, inderterminateZE, checkedZE;
    UiCheckboxesStatus one = UNCHECKED, two = INDERTERMINATE, three = CHECKED;

public:
    CheckboxesSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_CHECKBOXESSAMPLE_HH
