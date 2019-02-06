//
// Created by Loïs Boubault on 2019-01-23.
//

#ifndef VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH
#define VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH


#include "../kit/core/View.hh"
#include "../kit/utils/IME.hpp"

#define NUMBER_OF_BUTTONS_TEXTFIELDS 7

class TextFieldsSample : public View {
private:
    int selector = 1;
    std::string singleLeadingIcon, singleTrailingIcon, singleSuffixText, singlePrefixText, multiple, textarea;
    ZoneEventTextField singleLeadingIconEvent, singleTrailingIconEvent, singleSuffixTextEvent, singlePrefixTextEvent, multipleEvent, textareaEvent;
    ZoneEvent back;
    IME *ime;
public:
    TextFieldsSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH
