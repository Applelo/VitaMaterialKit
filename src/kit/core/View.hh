#ifndef VITAMATERIALKIT_VIEW_HH
#define VITAMATERIALKIT_VIEW_HH

#include "ViewsController.hh"
#include "Ui.hh"
#include "Utils.hh"


class View {
protected:
 const char *name;
 Ui *ui;
 ViewsController *viewsController;
 Utils *utils;

public:
    View(const char *name);

    virtual void content();
    virtual void controls();

    const char *getName() const;

    void setViewsController(ViewsController *viewsController);
    void setUi(Ui *ui);
    void setUtils(Utils *utils);


};


#endif //VITAMATERIALKIT_VIEW_HH
