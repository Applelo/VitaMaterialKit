#ifndef VITAMATERIALKIT_VIEW_HH
#define VITAMATERIALKIT_VIEW_HH

#include "ViewsController.hh"
#include "Ui.hh"



class View {
protected:
 const char *name;
 Ui *ui;
 ViewsController *viewsController;
 Pad *pad;
 Touch *touch;

public:
    View(const char *name);

    virtual void content();
    virtual void controls();

    const char *getName() const;

    void setViewsController(ViewsController *viewsController);
    void setUi(Ui *ui);
    void setPad(Pad *pad);
    void setTouch(Touch *touch);


};


#endif //VITAMATERIALKIT_VIEW_HH
