#include "Utils.hh"

Utils::Utils() {
    this->init();
}

void Utils::init() {
   this->touch = new Touch();
   this->pad = new Pad();
}

void Utils::read() {
    pad->read();
    touch->read();
}

