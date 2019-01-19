#ifndef VITAMATERIALKIT_BUTTONSSAMPLE_HH
#define VITAMATERIALKIT_BUTTONSSAMPLE_HH


#include "../kit/core/View.hh"

class ButtonsSample : public View {
private:
    TouchZoneEvent back;
public:
    ButtonsSample(std::string name);

    void contents() override;
    void controls() override;
};


#endif //VITAMATERIALKIT_BUTTONSSAMPLE_HH
