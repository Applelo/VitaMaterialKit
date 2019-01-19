#ifndef VITAMATERIALKIT_APP_HH
#define VITAMATERIALKIT_APP_HH

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
#include <map>
#include "View.hh"
#include "ViewsController.hh"
#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"
#include "Ui.hh"

class App {
private:
    ViewsController *viewsController;

    Touch *touch;
    Pad *pad;

    Ui *ui;
    UiIcons *icons;
    vita2d_font *font;
    std::map<const char *, View *> views;
    int run;
public:
    App(const char *firstView);
    App(Ui *ui, const char *firstView);

    void insertView(View *view);
    void main();
    void checkExit();
};


#endif //VITAMATERIALKIT_APP_HH
