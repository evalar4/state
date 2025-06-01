#include <iostream>
#include "ForenoonState.h"
#include "Work.h"
#include "NoonState.h"

void ForenoonState::writeProgram(Work* w) {
    if(w->getHour() < 12) {
        std::cout << "Current time: " << w->getHour() 
                  << " - Working energetically (Forenoon State)\n";
    } else {
        w->setState(new NoonState());
        w->writeProgram();
    }
}