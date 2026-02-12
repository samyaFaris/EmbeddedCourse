#include <iostream>
using namespace std;
#include <string.h>
#include "employee.h"

employee::employee(const person &p, const int workerId) : person(p)
{
    this->workerId = workerId;
}
employee::employee(const char *personId, const char *personName, const int workerId):person(personId,personName)
{
this->workerId=workerId;
}
employee::employee(person &&p, int workerId): person (std::move(p))
{
            cout << "move employee";
       
        this->workerId = workerId;

}
const int employee::get_workerId()const
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
    os << "Worker Id: "<< emp.workerId;
    return os;
}