#ifndef __PATIENT_H
#define __PATIENT_H
#include <iostream>
using namespace std;
#include "person.h"

class visit;

class patient : public person
{

private:

    int year;
    string gender;
    visit **visitsP_arr;
    int visit_logical_size;
    int visit_physical_size;

public:
    patient(const string &personId, const string &personName, const int year, const string &gender);
    int get_year() const;
    const string& get_gender() const;
    visit **get_visitP() const;
    bool set_year(int year);
    bool set_gender(const string &gender);
    bool add_visit_patient(visit *visitPtr);
    friend ostream &operator<<(ostream &os, const patient &p);
};

#endif