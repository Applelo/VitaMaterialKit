#include "View.hh"

View::View(const char *name)  {
    this->name = name;
}

const char *View::getName() const {
    return name;
}

void View::content() {
//nia
}

void View::controls() {
//nio
}

void View::setTexts(Texts *texts) {
    this->texts = texts;
}

void View::setViewsController(ViewsController *viewsController) {
    this->viewsController = viewsController;
}

void View::setTheme(Theme *theme) {
    this->theme = theme;
}
