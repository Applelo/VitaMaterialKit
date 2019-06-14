#ifndef VITAMATERIALKIT_UTILSSCROLL_HH
#define VITAMATERIALKIT_UTILSSCROLL_HH


#include "UtilsTouch.hpp"
#include "UtilsPad.hpp"

#include <string>
#include <map>

typedef enum ScrollDirection {
    SCROLL_DIR_X,
    SCROLL_DIR_Y
} ScrollDirection;

typedef struct ScrollChannelData {
    ScrollDirection scrollDirection;
    int max;
    int min;
    int value;
    int xZone;
    int yZone;
    int widthZone;
    int heightZone;
} ScrollChannelData;

class UtilsScroll {
private:
    UtilsTouch *touch;

    std::map<std::string, ScrollChannelData> channels;

public:
    UtilsScroll();
    UtilsScroll(UtilsTouch *touch);

    void create(const std::string& channel, ScrollDirection scrollDirection, int min, int max, int xZone, int yZone, int widthZone, int heightZone);
    void remove(const std::string& channel);

    void padController(const std::string& channel, int value);
    void touchController(const std::string& channel);

    int getScroll(std::string channel);

};


#endif //VITAMATERIALKIT_UTILSSCROLL_HH
