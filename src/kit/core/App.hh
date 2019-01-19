#ifndef VITAMATERIALKIT_APP_HH
#define VITAMATERIALKIT_APP_HH

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
#include <map>
#include "View.hh"
#include "ViewsController.hh"
#include "Ui.hh"
#include "Utils.hh"

class App {
private:
    ViewsController *viewsController;

    Utils *utils;

    Ui *ui;
    std::map<const char *, View *> views;
    int run;
    void insertView(View *view);
    void main();
    void checkExit();
    void initVita2d();
public:
    App(const char *firstView);
    App(Ui *ui, Utils *utils, const char *firstView);
};


#endif //VITAMATERIALKIT_APP_HH
