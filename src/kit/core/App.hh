#ifndef VITAMATERIALKIT_APP_HH
#define VITAMATERIALKIT_APP_HH

#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
#include <map>
#include "View.hh"
#include "ViewsController.hh"
#include "../../app/Ui.hh"
#include "../../app/Utils.hh"
#include "Debug.hh"

class App {
private:
    void checkExit();
    void initVita2d();
    void mountViews();

protected:
    Utils *utils;
    Ui *ui;
    ViewsController *viewsController;
    std::map<std::string, View *> views;
    int run;
    std::string oldViewName;

    //hook can be override
    virtual void beforeMountViews();
    virtual void beforeView();
    virtual void afterView();
    virtual void debug();
public:
    static bool disableViewContents;
    App(const char *firstView);

    void insertView(View *view);
    void main();

    static bool isDisableViewContents();
    static void setDisableViewContents(bool disableViewContents);
};


#endif //VITAMATERIALKIT_APP_HH
