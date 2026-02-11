#include <iostream>
using namespace std;
#include <string.h>
#include "employee.h"

employee::employee(const person &p, const int workerId) : person(p)
{
    this->workerId = workerId;
}

int employee::get_workerId()
{
    return this->workerId;
}
bool employee::set_workerId(int workerId)
{
    this->workerId = workerId;
    return true;
}
ostream &operator<<(ostream &os, const employee &emp)
{
    os <<"-------Employee Details -------\n";
    os << (person&)emp ;
    os << "Worker Id: "<< emp.workerId;
    return os;
}