#ifndef __DOCTORRESEARCHER_H
#define __DOCTORRESEARCHER_H
#include <iostream>
#include "doctor.h"
#include "researcher.h"
using namespace std;

class doctorResearcher : public doctor, public researcher
{
public:
    doctorResearcher(const string& doctor_researcher_name, const string& doctor_researcher_id, int idCounter,const string& experties);
    friend ostream &operator<<(ostream &os, const doctorResearcher &dr);
};

#endif