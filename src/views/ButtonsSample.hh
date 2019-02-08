#ifndef VITAMATERIALKIT_BUTTONSSAMPLE_HH
#define VITAMATERIALKIT_BUTTONSSAMPLE_HH


#include "../kit/core/View.hh"

class ButtonsSample : public View {
private:
    ZoneEvent back;
public:
    ButtonsSample(const std::string &name);

    void contents() override;
    void controls() override;

    void beforeEnter() override;
};


#endif //VITAMATERIALKIT_BUTTONSSAMPLE_HH
