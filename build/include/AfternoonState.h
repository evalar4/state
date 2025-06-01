#ifndef _AFTERNOON_STATE_H_
#define _AFTERNOON_STATE_H_

#include "State.h"

class AfternoonState : public State {
public:
    void writeProgram(Work* w) override;
};

#endif