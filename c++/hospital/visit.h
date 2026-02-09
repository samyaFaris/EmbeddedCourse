#ifndef __VISIT_H
#define __VISIT_H
#include <iostream>
using namespace std;

class patient;

class visit
{
private:
    char *visit_date;
    const patient *patientPtr;

public:
    visit(const char *visit_date, const patient *patientPtr);
    char *get_visit_date();
    const patient *  get_patientPtr();
    bool set_visit_date(char *visit_date);
    bool set_patientPtr(patient *patientPtr);
    ~visit();
    friend ostream &operator<<(ostream &os, const visit &v);
};

#endif