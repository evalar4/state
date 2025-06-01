#ifndef FORENOON_STATE_H
#define FORENOON_STATE_H

#include "State.h"

class ForenoonState : public State {
public:
    void writeProgram(Work* w) override;
};

#endif