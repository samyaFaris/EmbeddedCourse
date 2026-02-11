#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
using namespace std;
#include "person.h"

class employee : public person
{
protected:
    int workerId;

public:
    employee(const person &p, const int workerId);
    int get_workerId();
    bool set_workerId(int workerId);
    friend ostream &operator<<(ostream &os, const employee &emp);
};

#endif