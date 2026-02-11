#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
#include "employee.h"
using namespace std;
class department;

class doctor :  virtual public employee
{

protected:
    char *experties;
    department *departmentPtr;
    doctor(const doctor &d);
    doctor(doctor &&d);
    const doctor &operator=(const doctor &d);

public:
    doctor(const employee &emp, const char *experties);
    ~doctor();
    department *get_departmentPtr() ;
    const char *get_worker_experties() const;
    bool set_worker_experties(char *experties);
    bool set_departmentPtr(department *departmentPtr);
    friend ostream &operator<<(ostream &os, const doctor &d);
};

#endif