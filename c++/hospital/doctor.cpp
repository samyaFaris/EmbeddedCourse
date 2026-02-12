#include <iostream>
using namespace std;
#include "doctor.h"
#include <string.h>
#include "department.h"

doctor::doctor(const employee &emp, const char *experties) : employee(emp)
{

    this->experties = new char[strlen(experties) + 1];
    strcpy(this->experties, experties);
    this->departmentPtr = nullptr;
}
doctor::doctor(const char *doctorName, const char *doctorId, int idCount, const char *experties) : employee(doctorId,doctorName,idCount)
{
    this->experties = new char[strlen(experties) + 1];
    strcpy(this->experties, experties);
    this->departmentPtr = nullptr;
}

doctor::doctor(employee &&emp, const char *experties) : employee(std::move(emp))
{
    cout << "move doctor";
    this->experties = new char[strlen(experties) + 1];
    strcpy(this->experties, experties);
    this->departmentPtr = nullptr;
}

doctor::doctor(const doctor &d) : employee(d)
{
    *this = d;
}
doctor::doctor(doctor &&d) : employee(std::move(d))
{
    this->experties = d.experties;
    d.experties = nullptr;
}
const char *doctor::get_worker_experties() const
{
    return this->experties;
}
department *doctor::get_departmentPtr()
{
    return this->departmentPtr;
}

bool doctor::set_worker_experties(char *experties)
{
    delete[] experties;
    this->experties = new char[strlen(experties) + 1];
    strcpy(this->experties, experties);
    return true;
}
bool doctor::set_departmentPtr(department *departmentPtr)
{
    this->departmentPtr = departmentPtr;
    return true;
}
doctor::~doctor()
{

    delete[] experties;
}
const doctor &doctor::operator=(const doctor &d)
{
    if (this != &d)
    {
        employee::operator=(d);
        this->experties = new char[strlen(experties) + 1];
        strcpy(this->experties, experties);
    }
    return *this;
}
ostream &operator<<(ostream &os, const doctor &d)
{
    os << "--------- DOCTOR DETAILS --------- \n";
    os << (employee &)d;
    os << "Experties: " << d.experties << "\n";
    if (d.departmentPtr != nullptr)
    {
        os << "Department Name: " << (d.departmentPtr)->get_dep_name() << "\n";
    }

    return os;
}