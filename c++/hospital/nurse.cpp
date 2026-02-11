#include <iostream>
using namespace std;
#include "nurse.h"
#include <string.h>
#include "department.h"

nurse::nurse(const employee &e, int experienceYears) : employee(e)
{
    this->experienceYears = experienceYears;
}
int nurse::get_experienceYears()
{
    return this->experienceYears;
}
department *nurse::get_departmentPtr()
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