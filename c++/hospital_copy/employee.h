#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
using namespace std;
#include "person.h"

class employee : public person
{
protected:
    int workerId;
    employee(const string& personId, const string& personName,  int workerId);


public:
    int get_workerId() const;
    bool set_workerId(int workerId);
    friend ostream &operator<<(ostream &os, const employee &emp);
};

#endif