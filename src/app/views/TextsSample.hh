#ifndef VITAMATERIALKIT_TEXTSSAMPLE_HH
#define VITAMATERIALKIT_TEXTSSAMPLE_HH


#include "../../kit/core/View.hh"

class TextsSample : public View {
private:
    ZoneEvent back;
public:
    TextsSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_TEXTSSAMPLE_HH
