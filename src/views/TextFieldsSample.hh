//
// Created by Loïs Boubault on 2019-01-23.
//

#ifndef VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH
#define VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH


#include "../kit/core/View.hh"

#define NUMBER_OF_BUTTONS_TEXTFIELDS 2

class TextFieldsSample : public View {
private:
    int selector = 1;
    ZoneEventTextField textFieldFilledBasic;
    ZoneEvent back;
public:
    TextFieldsSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH
