#include "Utils.hh"

Utils::Utils() {
    this->init();
}

void Utils::init() {
   this->touch = new Touch();
   this->pad = new Pad();
   this->i18n = new I18n();
   this->PTC = new PadTouchCtrl(this->pad, this->touch);
}

void Utils::read() {
    pad->read();
    touch->read();
    PTC->controller();
}

