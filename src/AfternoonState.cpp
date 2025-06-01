#include <iostream>
#include "AfternoonState.h"
#include "Work.h"

void AfternoonState::writeProgram(Work* w) {
    if(w->getHour() < 17) {
        std::cout << "Current time: " << w->getHour()
                  << " - Want to go home (Afternoon State)\n";
    }
    // No state transition for hours >= 17
}