//
// Created by Loïs Boubault on 2019-01-15.
//

#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {

}

void Welcome::content() {
    texts->draw(0,0,H1, "Welcome");
}
