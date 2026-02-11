#ifndef __PATIENT_H
#define __PATIENT_H
#include <iostream>
using namespace std;
#include "person.h"

class visit;

class patient : public person
{

private:
    // char *patient_id;
    // char *patient_name;
    int year;
    char *gender;
    visit **visitsP_arr;
    int visit_logical_size;
    int visit_physical_size;
    patient(patient &p) = delete;

public:
    patient(const person& p, const int year, const char *gender);
    char *get_patient_id();
    const char *get_patient_name() const;
    int get_year();
    char *get_gender();
    int get_visit_logical_size();
    int get_visit_physical_size();
     visit ** get_visitP();
    bool set_patient_name(char *patient_name);
    bool set_year(int year);
    bool set_gender(char *gender);
    bool set_visit_logical_size(int visit_logical_size);
    bool set_visit_physical_size(int visit_physical_size);
    bool add_visit_patient(visit* visitPtr);
    ~patient();
    friend ostream &operator<<(ostream &os, const patient &p);
};

#endif