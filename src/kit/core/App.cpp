#include "App.hh"

App::App(Ui *ui, const char *firstView) {
    this->ui = ui;
    this->viewsController = new ViewsController((char*) firstView);

    this->touch = new Touch();
    this->pad = new Pad();

    run = 1;
}


void App::insertView(View *view) {
    view->setViewsController(this->viewsController);
    view->setUi(this->ui);
    view->setPad(this->pad);
    view->setTouch(this->touch);
    views[view->getName()] = view;
}


int App::main() {
    vita2d_init();
    vita2d_set_clear_color((unsigned int) RGBA8(218, 219, 219, 255));

    while (run) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        pad->read();
        touch->read();

        views[viewsController->getActualView()]->content();
        views[viewsController->getActualView()]->controls();

        this->checkExit();

        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();
    sceKernelExitProcess(0);
    return 0;
}

void App::checkExit() {

    if (viewsController->getActualView() == (char *) VIEWS_CONTROLLER_EXIT) {
        run = 0;
    }
};