#ifndef VITAMATERIALKIT_I18NSAMPLE_HH
#define VITAMATERIALKIT_I18NSAMPLE_HH

#include "../kit/core/View.hh"

class I18nSample: public View {
private:
    TouchZoneEvent back;
    I18n *frLang = new I18n(SCE_SYSTEM_PARAM_LANG_FRENCH);
    I18n *enLang = new I18n(SCE_SYSTEM_PARAM_LANG_ENGLISH_US);
public:
    I18nSample(const char *name);
    void contents() override;
    void controls() override;
};

#endif //VITAMATERIALKIT_I18NSAMPLE_HH
