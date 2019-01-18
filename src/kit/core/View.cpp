#include "View.hh"

View::View(const char *name)  {
    this->name = name;
}

const char *View::getName() const {
    return name;
}

void View::content() {
//display stuff go here
}

void View::controls() {
//controls go here
}

void View::setUi(Ui *ui) {
    View::ui = ui;
}

void View::setViewsController(ViewsController *viewsController) {
    View::viewsController = viewsController;
}

void View::setPad(Pad *pad) {
    View::pad = pad;
}

void View::setTouch(Touch *touch) {
    View::touch = touch;
}

