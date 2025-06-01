#ifndef _NOON_STATE_H_
#define _NOON_STATE_H_

#include "State.h"

class NoonState : public State {
public:
    void writeProgram(Work* w) override;
};

#endif