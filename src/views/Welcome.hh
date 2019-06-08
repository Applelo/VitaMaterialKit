#ifndef VITAMATERIALKIT_WELCOME_HH
#define VITAMATERIALKIT_WELCOME_HH

#include "../kit/core/View.hh"

class Welcome: public View {
private:
    ZoneEvent buttonsTZE;
    ZoneEvent i18nTZE;
    ZoneEvent iconsTZE;
    ZoneEvent textsTZE;
    ZoneEvent checkboxesTZE;
    ZoneEvent textfieldsTZE;
    ZoneEvent cardsTZE;
    ZoneEvent exitTZE;

public:
    Welcome(const char *name);
    void contents() override;
    void controls() override;
    int getXMenuItemPosition(int item);

    void beforeEnter() override;
};

#endif //VITAMATERIALKIT_WELCOME_HH
