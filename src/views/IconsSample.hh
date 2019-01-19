//
// Created by Loïs Boubault on 2019-01-19.
//

#ifndef VITAMATERIALKIT_ICONSSAMPLE_HH
#define VITAMATERIALKIT_ICONSSAMPLE_HH


#include "../kit/core/View.hh"

class IconsSample : public View {
private:
    TouchZoneEvent back;
public:
    IconsSample(const std::string &name);

    void contents() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_ICONSSAMPLE_HH
