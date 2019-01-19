#ifndef VITAMATERIALKIT_WELCOME_HH
#define VITAMATERIALKIT_WELCOME_HH

#include "../kit/core/View.hh"

class Welcome: public View {
private:
    TouchZoneEvent buttonsTZE;
    TouchZoneEvent i18nTZE;
    TouchZoneEvent iconsTZE;
    TouchZoneEvent textsTZE;
    TouchZoneEvent imeTZE;
    TouchZoneEvent exitTZE;

public:
    Welcome(const char *name);
    void contents() override;
    void controls() override;
};

#endif //VITAMATERIALKIT_WELCOME_HH
