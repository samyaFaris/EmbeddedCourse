#ifndef __NURSE_H
#define __NURSE_H
#include <iostream>
#include "employee.h"
using namespace std;
class department;

class nurse : public employee
{
private:
    int experienceYears;
    department *departmentPtr;

public:
    nurse(const employee &e, int experienceYears);
    nurse(const char *nurseName ,const char *nurseId,int idCount, int experienceYears);
    int get_experienceYears();
    department *get_departmentPtr();
    bool set_experienceYears(int experienceYears);
    bool set_departmentPtr(department *departmentPtr);
    friend ostream &operator<<(ostream &os, const nurse &n);
};

#endif