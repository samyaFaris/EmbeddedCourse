#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include "doctor.h"
#include "nurse.h"
using namespace std;

class department
{
private:
    string dep_name;
    doctor **doctor_arr;
    nurse **nurse_arr;
    int Physical_size;
    int logical_size;
    int nurse_Physical_size;
    int nurse_logical_size;

public:
    department(const string& dep_name);
    bool set_dep_name(string& dep_name);
    const string& get_dep_name() const;
    doctor **get_doctor_arr() const;
    nurse **get_nurse_arr() const;
    ~department();
    bool add_doctor_to_dep(doctor *doctorPtr);
    bool add_nurse_to_dep(nurse *nursePtr);
    friend ostream &operator<<(ostream &os, const department &d);
};

#endif