#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
#include "employee.h"
using namespace std;
class department;

class doctor :  virtual public employee
{

protected:
    string experties;
    department *departmentPtr;


public:
    doctor(const string& doctorName, const string& doctorId, int idCount,const string& experties);
    department *get_departmentPtr()const;
    const string& get_worker_experties() const;
    bool set_worker_experties(const string& experties);
    bool set_departmentPtr(department *departmentPtr);
    friend  ostream &operator<<(ostream &os, const doctor &d);
};

#endif