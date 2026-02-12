#include <iostream>
using namespace std;
#include <string.h>
#include "person.h"

person::person(const string &personId, const string &personName)
{
    this->personId = personId;
    this->personName = personName;
}

const string &person::get_person_id() const
{
    return this->personId;
}
const string &person::get_personName() const
{
    return this->personName;
}
bool person::set_person_id(const string &personId)
{
    this->personId = personId;
    return true;
}
bool person::set_personName(const string &personName)
{
    this->personName = personName;
    return true;
}
ostream &operator<<(ostream &os, const person &p)
{
    os << "Person Id: " << p.personId << "\n";
    os << "Name: " << p.personName << "\n";
    return os;
}
