#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
using namespace std;
#include "person.h"

class employee : public person
{
protected:
    int workerId;
    employee(const char *personId, const char *personName, const int workerId);
    employee(const person &p, const int workerId);
    employee(person &&p, int workerId);

public:
    // employee(const person &p, const int workerId);
    // employee(person &&p, int workerId);
    const int get_workerId() const;
    bool set_workerId(int workerId);
    friend ostream &operator<<(ostream &os, const employee &emp);
};

#endif