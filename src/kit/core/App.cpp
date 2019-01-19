#include "App.hh"

App::App(const char *firstView) {
    this->initVita2d();

    this->ui = new Ui();
    this->utils = new Utils();
    this->viewsController = new ViewsController((char*) firstView);

    run = 1;
};

App::App(Ui *ui, Utils *utils, const char *firstView) {
    this->initVita2d();

    this->ui = ui;
    this->utils = utils;
    this->viewsController = new ViewsController((char*) firstView);

    run = 1;
}


void App::insertView(View *view) {
    view->setViewsController(this->viewsController);
    view->setUi(this->ui);
    view->setUtils(this->utils);
    views[view->getName()] = view;
}


void App::main() {

    while (run) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        this->utils->read();

        if (this->views.find(viewsController->getActualView()) != this->views.end()) {
            this->views[viewsController->getActualView()]->content();
            this->views[viewsController->getActualView()]->controls();
        }

        this->checkExit();

        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

}

void App::checkExit() {

    if (strcmp(viewsController->getActualView(), VIEWS_CONTROLLER_EXIT_LOOP) == 0) {
        run = 0;
    }
    else if (strcmp(viewsController->getActualView(), VIEWS_CONTROLLER_EXIT) == 0) {
        vita2d_fini();
        sceKernelExitProcess(0);
    }
}

void App::initVita2d() {
    vita2d_init();
    vita2d_set_clear_color((unsigned int) RGBA8(218, 219, 219, 255));
}
