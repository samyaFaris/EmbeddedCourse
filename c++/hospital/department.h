#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include "doctor.h"
#include "nurse.h"
using namespace std;

class department
{
private:
    char *dep_name;
    doctor **doctor_arr;
    nurse **nurse_arr;
    int Physical_size;
    int logical_size;
    int nurse_Physical_size;
    int nurse_logical_size;

public:
    department(const char *dep_name);
    bool set_dep_name(char *dep_name);
    bool set_Physical_size(int size);
    bool set_logical_size(int size);
    bool set_nurse_Physical_size(int size);
    bool set_nurse_logical_size(int size);
    char *get_dep_name();
    int get_Physical_size();
    int get_logical_size();
    int get_nurse_Physical_size();
    int get_nurse_logical_size();
    doctor **get_doctor_arr();
    ~department();
    bool add_doctor_to_dep(doctor *doctorPtr);
    bool add_nurse_to_dep(nurse *nursePtr);
    friend ostream &operator<<(ostream &os, const department &d);
};

#endif