#include "Work.h"
#include "ForenoonState.h"

Work::Work() {
    current = new ForenoonState();
}

Work::~Work() {
    delete current;
}

void Work::setHour(double hour) {
    this->hour = hour;
}

void Work::setState(State* s) {
    delete current;
    current = s;
}

double Work::getHour() const {
    return hour;
}

void Work::writeProgram() {
    current->writeProgram(this);
}