#include <iostream>
using namespace std;
#include "doctor.h"
#include <string.h>
#include "department.h"


doctor::doctor(const string& doctorName, const string& doctorId, int idCount, const string& experties) : employee(doctorId,doctorName,idCount), departmentPtr(nullptr)
{
    this->experties =experties;
}


const string& doctor::get_worker_experties() const
{
    return this->experties;
}
department *doctor::get_departmentPtr() const
{
    return this->departmentPtr;
}

bool doctor::set_worker_experties(const string& experties)
{
  
    this->experties = experties;
    return true;
}
bool doctor::set_departmentPtr(department *departmentPtr)
{
    this->departmentPtr = departmentPtr;
    return true;
}

ostream &operator<<(ostream &os, const doctor &d)
{
  
    os << "--------- DOCTOR DETAILS --------- \n";
    os << (employee &)d;
    os << "Experties: " << d.experties << "\n";
 

    return os;
}