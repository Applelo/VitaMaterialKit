#ifndef VITAMATERIALKIT_WELCOME_HH
#define VITAMATERIALKIT_WELCOME_HH

#include "../kit/core/View.hh"

class Welcome: public View {
public:
    Welcome(const char *name);
    void content() override;
};

#endif //VITAMATERIALKIT_WELCOME_HH
