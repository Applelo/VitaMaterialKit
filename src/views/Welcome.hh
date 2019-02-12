#ifndef VITAMATERIALKIT_WELCOME_HH
#define VITAMATERIALKIT_WELCOME_HH

#include "../kit/core/View.hh"
#include "../kit/utils/UtilsTwitter.hh"

class Welcome: public View {
private:
    ZoneEvent buttonsTZE;
    ZoneEvent i18nTZE;
    ZoneEvent iconsTZE;
    ZoneEvent textsTZE;
    ZoneEvent checkboxesTZE;
    ZoneEvent textfieldsTZE;
    ZoneEvent exitTZE;
    UtilsTwitter twitter;

public:
    Welcome(const char *name);
    void contents() override;
    void controls() override;

    void beforeEnter() override;

    void mounted() override;
};

#endif //VITAMATERIALKIT_WELCOME_HH
