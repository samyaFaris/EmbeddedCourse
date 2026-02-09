#include <iostream>
using namespace std;
#include "doctor.h"
#include <string.h>
#include "department.h"

doctor::doctor(const char *name, int workerId, const char *experties) : dr_name(nullptr), experties(nullptr)
{
    this->dr_name = new char[strlen(name) + 1];
    strcpy(dr_name, name);
    this->worker_id = workerId;
    this->experties = new char[strlen(experties) + 1];
    strcpy(this->experties, experties);
}
doctor::doctor(doctor &d)
{
    this->dr_name = new char[strlen(d.dr_name) + 1];
    strcpy(dr_name, d.dr_name);
    this->worker_id = d.worker_id;
    this->experties = new char[strlen(d.experties) + 1];
    strcpy(this->experties, experties);
}

const char *doctor::get_dr_name() const
{
    return this->dr_name;
}
int doctor::get_worker_id() const
{
    return this->worker_id;
}
const char *doctor::get_worker_experties() const
{
    return this->experties;
}
department *doctor::get_departmentPtr()
{
    return this->departmentPtr;
}

bool doctor::set_dr_name(char *name)
{
    delete[] this->dr_name;
    this->dr_name = new char[strlen(name) + 1];
    strcpy(dr_name, name);
    return true;
}
bool doctor::set_worker_id(int id)
{
    this->worker_id = id;
    return true;
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
    delete[] dr_name;
    delete[] experties;
}
ostream &operator<<(ostream &os, const doctor &d)
{
    os << "Doctor Details \n";
    os << "name: " << d.dr_name << "\n";
    os << "Worker Id: " << d.worker_id << "\n";
    os << "Experties: " << d.experties << "\n";
    os << "Department Name: " <<  (d.departmentPtr)->get_dep_name() << "\n";

    return os;
}