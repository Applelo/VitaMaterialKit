#ifndef VITAMATERIALKIT_IMESAMPLE_HH
#define VITAMATERIALKIT_IMESAMPLE_HH


#include "../kit/core/View.hh"
#include "../kit/utils/IME.hpp"

class ImeSample: public View {
private:
    TouchZoneEvent back, keyboard;
    IME *ime;
    std::string result = "My text shows here";
public:
    ImeSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_IMESAMPLE_HH
