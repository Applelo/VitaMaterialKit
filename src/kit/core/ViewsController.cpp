#include "ViewsController.hh"

ViewsController::ViewsController(char *actualView) : actualView(actualView) {}

char *ViewsController::getActualView() const {
    return actualView;
}

void ViewsController::setActualView(char *actualView) {
    ViewsController::actualView = actualView;
}

