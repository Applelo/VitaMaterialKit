#ifndef VITAMATERIALKIT_APP_HH
#define VITAMATERIALKIT_APP_HH

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
#include <map>
#include "View.hh"
#include "ViewsController.hh"
#include "../../app/Ui.hh"
#include "../../app/Utils.hh"
#include "Config.hh"


class App {
private:
    void checkExit();
    void initVita2d();
    void launchMountedViews();

protected:
    Utils *utils;
    Ui *ui;
    ViewsController *viewsController;
    std::map<std::string, View *> views;
    int run;
    std::string oldViewName;

    virtual void beforeView();
    virtual void afterView();
    virtual void debug();
public:
    App(const char *firstView);

    void insertView(View *view);
    void main();
};


#endif //VITAMATERIALKIT_APP_HH
