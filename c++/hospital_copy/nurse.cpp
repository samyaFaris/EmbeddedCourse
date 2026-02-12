#include <iostream>
using namespace std;
#include "nurse.h"
#include <string.h>
#include "department.h"

nurse::nurse(const string& nurseName, const string& nurseId, int idCount, int experienceYears) : employee(nurseId, nurseName,idCount)
{
    this->experienceYears = experienceYears;
}

int nurse::get_experienceYears()const
{
    return this->experienceYears;
}
department *nurse::get_departmentPtr()const
{
    return this->departmentPtr;
}
bool nurse::set_experienceYears(int experienceYears)
{
    this->experienceYears = experienceYears;
    return true;
}
bool nurse::set_departmentPtr(department *departmentPtr)
{
    this->departmentPtr = departmentPtr;
    return true;
}
ostream &operator<<(ostream &os, const nurse &n)
{
    os << "----------------Nurse Details : ---------------------\n";
    os << (employee&)n;
    os << "experience Years" << n.experienceYears;
    os << "Department Name: " << (n.departmentPtr)->get_dep_name() << "\n";

    return os;
}