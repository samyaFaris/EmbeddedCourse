#ifndef __DOCTORRESEARCHER_H
#define __DOCTORRESEARCHER_H
#include <iostream>
#include "doctor.h"
#include "researcher.h"
using namespace std;

class doctorResearcher : public doctor, public researcher
{
    public: 
    doctorResearcher(const doctor&d, const researcher&r);
};

#endif