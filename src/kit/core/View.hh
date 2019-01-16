#ifndef VITAMATERIALKIT_VIEW_HH
#define VITAMATERIALKIT_VIEW_HH

#include "../ui/Texts.hpp"
#include "ViewsController.hh"
#include "../ui/Theme.hpp"

typedef struct ViewConfig {
    bool texts;
    bool ctrl;
    bool touch;
    bool icons;
} ViewConfig;

class View {
protected:
 const char *name;

 Theme *theme = nullptr;
 Texts *texts = nullptr;
 ViewsController *viewsController;


public:
    View(const char *name);

    virtual void content();
    virtual void controls();


    const char *getName() const;

    void setViewsController(ViewsController *viewsController);
    void setTexts(Texts *texts);
    void setTheme(Theme *theme);


};


#endif //VITAMATERIALKIT_VIEW_HH
