#ifndef VITAMATERIALKIT_I18NSAMPLE_HH
#define VITAMATERIALKIT_I18NSAMPLE_HH

#include "../../kit/core/View.hh"

class I18nSample: public View {
private:
    ZoneEvent back;
    UtilsI18n *frLang;
    UtilsI18n *enLang;
    std::map<std::string, std::string> defaultL, frL, enL;

public:
    I18nSample(const char *name);
    void contents() override;
    void controls() override;

    void mounted() override;
};

#endif //VITAMATERIALKIT_I18NSAMPLE_HH
