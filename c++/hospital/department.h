#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
#include "doctor.h"
using namespace std;

class department
{
private:
    char *dep_name;
    doctor **doctor_arr;
    int Physical_size;
    int logical_size;

public:
    department(const char *dep_name);
    bool set_dep_name(char *dep_name);
    bool set_Physical_size(int size);
    bool set_logical_size(int size);
    char *get_dep_name();
    int get_Physical_size();
    int get_logical_size();
    doctor **get_doctor_arr();
    ~department();
    bool add_doctor_to_dep(doctor *doctorPtr);
    friend ostream &operator<<(ostream &os, const department &d);
};

#endif