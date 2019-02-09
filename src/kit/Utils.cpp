#include "Utils.hh"

Utils::Utils() {
    this->init();
}

void Utils::init() {
   this->touch = new UtilsTouch();
   this->pad = new UtilsPad();
   this->i18n = new UtilsI18n();
   this->PTC = new UtilsPadTouchCtrl(this->pad, this->touch);
}

void Utils::read() {
    pad->read();
    touch->read();
    PTC->controller();
}

