#include <iostream>
using namespace std;
#include <string.h>
#include "employee.h"


employee::employee(const string& personId, const string& personName,  int workerId):person(personId,personName)
{
this->workerId=workerId;
}

int employee::get_workerId()const
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
    os << (person&)emp ;
    os << "Worker Id: "<< emp.workerId << "\n";
    return os;
}