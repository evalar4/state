#include <iostream>
#include "Work.h"

int main() {
    Work programmer;
    
    programmer.setHour(9);
    programmer.writeProgram();
    
    programmer.setHour(12);
    programmer.writeProgram();
    
    programmer.setHour(14);
    programmer.writeProgram();
    
    programmer.setHour(18);
    programmer.writeProgram();

    return 0;
}