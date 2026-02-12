#ifndef __DOCTORRESEARCHER_H
#define __DOCTORRESEARCHER_H
#include <iostream>
#include "doctor.h"
#include "researcher.h"
using namespace std;

class doctorResearcher : public doctor, public researcher
{
public:
    doctorResearcher(const doctor &d, const researcher &r);
    doctorResearcher(const char *doctor_researcher_name, const char *doctor_researcher_id, int idCounter,const char *experties);
    doctorResearcher(doctor &&d, researcher &&r);
    friend ostream &operator<<(ostream &os, const doctorResearcher &dr);
};

#endif