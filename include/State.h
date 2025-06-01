#ifndef STATE_H
#define STATE_H

class Work;

class State {
public:
    virtual ~State() = default;
    virtual void writeProgram(Work* w) = 0;
};

#endif