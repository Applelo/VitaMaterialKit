#ifndef VITAMATERIALKIT_APP_HH
#define VITAMATERIALKIT_APP_HH

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
#include <map>
#include "../ui/Theme.hpp"
#include "View.hh"
#include "../ui/Texts.hpp"
#include "ViewsController.hh"
#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

class App {
private:
    ViewsController *viewsController;

    Touch *touch;
    Pad *pad;

    Theme *theme;
    Texts *texts;
    std::map<const char *, View *> views;
    int run;
public:
    App(Theme *them, const char *firstView);
    ~App();

    void insertView(View *view);
    void insertView(View *view, ViewConfig viewConfig);
    void main();
    void checkExit();
};


#endif //VITAMATERIALKIT_APP_HH
