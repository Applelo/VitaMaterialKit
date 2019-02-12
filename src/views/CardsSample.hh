#ifndef VITAMATERIALKIT_CARDSSAMPLE_HH
#define VITAMATERIALKIT_CARDSSAMPLE_HH


#include "../kit/core/View.hh"

class CardsSample : public View {
private:
    CardPrePrimaryTitle cardPrePrimaryTitle;
    CardPreSummary cardPreSummary;

public:
    CardsSample(const std::string &name);

    void contents() override;

    void mounted() override;

    void controls() override;
};


#endif //VITAMATERIALKIT_CARDSSAMPLE_HH
