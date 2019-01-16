#ifndef VITAMATERIALKIT_VIEWSCONTROLLER_HH
#define VITAMATERIALKIT_VIEWSCONTROLLER_HH

#define VIEWS_CONTROLLER_EXIT "VIEWS_CONTROLLER_EXIT"
#define VIEWS_CONTROLLER_EXIT_LOOP "VIEWS_CONTROLLER_EXIT_LOOP"

class ViewsController {
private:
    char *actualView;
public:
    ViewsController(char *actualView);

    char *getActualView() const;
    void setActualView(char *actualView);
};


#endif //VITAMATERIALKIT_VIEWSCONTROLLER_HH
