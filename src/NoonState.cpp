#include <iostream>
#include "NoonState.h"
#include "Work.h"
#include "AfternoonState.h"

void NoonState::writeProgram(Work* w) {
    if(w->getHour() < 13) {
        std::cout << "Current time: " << w->getHour()
                  << " - Feeling sleepy after lunch (Noon State)\n";
    } else {
        w->setState(new AfternoonState());
        w->writeProgram();
    }
}