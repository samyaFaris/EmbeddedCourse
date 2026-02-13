#ifndef __PATIENT_H
#define __PATIENT_H
#include <iostream>
using namespace std;
#include "person.h"
#include <list>

class visit;

class patient : public person
{

private:
    int year;
    string gender;
    list<visit * > visitsP_arr; //

public:
    patient(const string &personId, const string &personName, const int year, const string &gender);
    int get_year() const;
    const string &get_gender() const;
    const list<visit*> &get_visitP() const; //
    bool set_year(int year);
    bool set_gender(const string &gender);
    bool add_visit_patient(visit *visitPtr);
    friend ostream &operator<<(ostream &os, const patient &p);
    virtual ~patient() {}
};

#endif