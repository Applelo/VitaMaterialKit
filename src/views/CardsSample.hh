//
// Created by Loïs Boubault on 2019-02-09.
//

#ifndef VITAMATERIALKIT_CARDSSAMPLE_HH
#define VITAMATERIALKIT_CARDSSAMPLE_HH


#include "../kit/core/View.hh"

class CardsSample : public View {
private:
public:
    CardsSample(const std::string &name);

    void contents() override;

    void mounted() override;
};


#endif //VITAMATERIALKIT_CARDSSAMPLE_HH
