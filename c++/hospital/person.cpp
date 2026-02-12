#include <iostream>
using namespace std;
#include <string.h>
#include "person.h"

person::person(const char *personId, const char *personName) :personId(nullptr), personName(nullptr)
{
    this->personId = new char[strlen(personId) + 1];
    strcpy(this->personId, personId);
    this->personName = new char[strlen(personName) + 1];
    strcpy(this->personName, personName);
}
person::person(const person &p)
{
    *this = p;
}
person::person(person &&p)
{
        cout << "move person";

    this->personId = p.personId;
    p.personId = nullptr;
    this->personName = p.personName;
    p.personName = nullptr;
}
person::~person()
{
    delete[] personId;
    delete[] personName;
}
const char *person::get_person_id() const
{
    return this->personId;
}
const char *person::get_personName() const
{
    return this->personName;
}
bool person::set_person_id(const char *personId)
{
    delete[] this->personId;
    this->personId = new char[strlen(personId) + 1];
    strcpy(this->personId, personId);
    return true;
}
bool person::set_personName(const char *personName)
{
    delete[] this->personName;
    this->personName = new char[strlen(personName) + 1];
    strcpy(this->personName, personName);
    return true;
}
const person &person::operator=(const person &p)
{
    if (this != &p)
    {
        if (this->personId != nullptr)
        {
            delete[] this->personId;
        }
        this->personId = new char[strlen(p.personId) + 1];
        strcpy(this->personId, p.personId);

        if (this->personName != nullptr)
        {
            delete[] this->personName;
        }
        this->personName = new char[strlen(p.personName) + 1];
        strcpy(this->personName, p.personName);
    }
    return *this;
}
ostream &operator<<(ostream &os, const person &p)
{
    os << "Person Id: " << p.personId << "\n";
    os << "Name: " << p.personName <<"\n";
    return os;
}
