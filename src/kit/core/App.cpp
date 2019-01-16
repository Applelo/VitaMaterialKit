#include "App.hh"

App::App(Ui *ui, const char *firstView) {

    this->ui = new Ui();
    this->viewsController = new ViewsController((char*) firstView);

    this->touch = new Touch();
    this->pad = new Pad();

    run = 1;

    vita2d_init();
    vita2d_set_clear_color((unsigned int) RGBA8(218, 219, 219, 255));
}

App::~App() {
    vita2d_fini();
    sceKernelExitProcess(0);
}


void App::insertView(View *view) {
    view->setViewsController(viewsController);
    view->setUi(ui);
    view->setPad(pad);
    view->setTouch(touch);
    views[view->getName()] = view;
}


void App::main() {
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
}

void App::checkExit() {

    if (viewsController->getActualView() == (char *) VIEWS_CONTROLLER_EXIT) {
        delete this;
    }
    else if (viewsController->getActualView() == (char *) VIEWS_CONTROLLER_EXIT_LOOP) {
        run = 0;
    }
};