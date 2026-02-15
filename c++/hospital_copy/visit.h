#ifndef __VISIT_H
#define __VISIT_H
#include <iostream>
using namespace std;
#include <string.h>

class patient;
class department;
class employee;

class visit
{
private:
    string visit_date;
    const patient *patientPtr;
    string visit_purpose;
    department *depPtr;
    employee * employeePtr;

public:
    visit(const string &visit_date, patient *patientPtr,string visit_purpose,department *depPtr,  employee * employeePtr);
    const string &get_visit_date() const;
    const patient *get_patientPtr() const;
    bool set_visit_date(const string &visit_date);
    bool set_patientPtr(patient *patientPtr);
    friend ostream &operator<<(ostream &os, const visit &v);
    virtual ~visit() {}
};

#endif