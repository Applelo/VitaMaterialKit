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
    std::map<std::string, View *> views;
    int run;
    void checkExit();
    void initVita2d();
    void debug();
public:
    App(const char *firstView);
    App(Ui *ui, Utils *utils, const char *firstView);

    void insertView(View *view);
    void main();
};


#endif //VITAMATERIALKIT_APP_HH
