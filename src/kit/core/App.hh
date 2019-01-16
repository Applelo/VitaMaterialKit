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

    std::map<const char *, View *> views;
    int run;
public:
    App(Ui *ui, const char *firstView);
    ~App();

    void insertView(View *view);
    void main();
    void checkExit();
};


#endif //VITAMATERIALKIT_APP_HH
