#ifndef WORK_H
#define WORK_H

class State;

class Work {
public:
    Work();
    ~Work();
    
    void setHour(double hour);
    void setState(State* s);
    double getHour() const;
    void writeProgram();

private:
    State* current;
    double hour;
};

#endif