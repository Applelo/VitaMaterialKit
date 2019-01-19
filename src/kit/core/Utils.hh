//
// Created by Loïs Boubault on 2019-01-19.
//

#ifndef VITAMATERIALKIT_UTILS_HH
#define VITAMATERIALKIT_UTILS_HH


#include "../utils/I18n.hpp"
#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

class Utils {
    Touch *touch;
    Pad *pad;
    I18n *i18n;
protected:
    virtual void init();
public:
    Utils();
    virtual void read();
};


#endif //VITAMATERIALKIT_UTILS_HH
