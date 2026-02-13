#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include "doctor.h"
#include "nurse.h"
#include "surgeon.h"
#include "doctorResearcher.h"
using namespace std;
#include <list>

class department
{
private:
    string dep_name;
    list <doctor* >doctor_arr;
    list<nurse> nurse_arr;


public:
    department(const string& dep_name);
    bool set_dep_name(string& dep_name);
    const string& get_dep_name() const;
    const list <doctor* >& get_doctor_arr() const;
    const list<nurse>& get_nurse_arr() const;
    bool add_doctor_to_dep(doctor *doctorPtr);
    bool add_nurse_to_dep(nurse *nursePtr);
    friend ostream &operator<<(ostream &os, const department &d);
};

#endif