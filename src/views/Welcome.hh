#ifndef VITAMATERIALKIT_WELCOME_HH
#define VITAMATERIALKIT_WELCOME_HH

#include "../kit/core/View.hh"

#define NUMBER_OF_BUTTONS 7

class Welcome: public View {
private:
    ZoneEvent buttonsTZE;
    ZoneEvent i18nTZE;
    ZoneEvent iconsTZE;
    ZoneEvent textsTZE;
    ZoneEvent imeTZE;
    ZoneEvent checkboxesTZE;
    ZoneEvent exitTZE;
    int selector;

public:
    Welcome(const char *name);
    void contents() override;
    void controls() override;
};

#endif //VITAMATERIALKIT_WELCOME_HH
