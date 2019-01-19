#include "Utils.hh"

Utils::Utils() {
    this->init();
}

//override this function to change what you want to load
void Utils::init() {
   this->touch = new Touch();
   this->pad = new Pad();

   this->i18n = new I18n();
}

void Utils::read() {
    pad->read();
    touch->read();
}

