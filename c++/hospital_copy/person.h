#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
using namespace std;
#include <string.h>


class person
{
protected:
    string personId;
    string personName;
    person(const string& personId, const string& personName);


public:
    const string& get_person_id() const;
    const string& get_personName() const;
    bool set_person_id(const string& personId);
    bool set_personName(const string& personName);
    friend ostream &operator<<(ostream &os, const person &p);
};

#endif