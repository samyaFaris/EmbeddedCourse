#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
using namespace std;

class person
{
protected:
    char *personId;
    char *personName;

public:
    person(const char *personId, const char *personName);
    person(const person &p);
    person(person &&p);
    ~person();
    const person &operator=(const person &p);
    const char *get_person_id() const;
    const char *get_personName() const;
    bool set_person_id(const char *personId);
    bool set_personName(const char *personName);
    friend ostream &operator<<(ostream &os, const person &p);
};

#endif