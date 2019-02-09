//
// Created by Loïs Boubault on 2019-01-23.
//

#ifndef VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH
#define VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH


#include "../kit/core/View.hh"
#include "../kit/utils/UtilsIME.hpp"

#define NUMBER_OF_BUTTONS_TEXTFIELDS 7

class TextFieldsSample : public View {
private:
    int selector = 1;
    std::string singleLeadingIcon, singleTrailingIcon, singleSuffixText, singlePrefixText, textarea;
    ZoneEventTextField singleLeadingIconEvent, singleTrailingIconEvent, singleSuffixTextEvent, singlePrefixTextEvent, textareaEvent;
    ZoneEvent back;
    UtilsIME *ime;
public:
    TextFieldsSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_TEXTFIELDSSAMPLE_HH
