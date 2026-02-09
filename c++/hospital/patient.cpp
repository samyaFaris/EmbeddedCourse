#include <iostream>
using namespace std;
#include <string.h>
#include "patient.h"
#include "visit.h"


patient::patient(const char *patient_id, const char *patient_name, const int year, const char *gender) : visit_logical_size(0), visit_physical_size(2)
{
    this->patient_id = new char[strlen(patient_id) + 1];
    strcpy(this->patient_id, patient_id);
    this->patient_name = new char[strlen(patient_name) + 1];
    strcpy(this->patient_name, patient_name);
    this->year = year;
    this->gender = new char[strlen(gender) + 1];
    strcpy(this->gender, gender);
    this->visitsP_arr = new visit *[visit_physical_size];
    for (int i = 0; i < visit_physical_size; i++)
    {
        visitsP_arr[i] = nullptr;
    }
}

char *patient::get_patient_id()
{
    return this->patient_id;
}
const char *patient::get_patient_name() const
{
    return this->patient_name;
}
int patient::get_year()
{
    return this->year;
}
char *patient::get_gender()
{
    return this->gender;
}
int patient::get_visit_logical_size()
{
    return visit_logical_size;
}
int patient::get_visit_physical_size()
{
    return visit_physical_size;
}
bool patient::set_visit_logical_size(int visit_logical_size)
{
    this->visit_logical_size = visit_logical_size;
    return true;
}
bool patient::set_visit_physical_size(int visit_physical_size)
{
    this->visit_physical_size = visit_physical_size;
    return true;
}
bool patient::set_patient_name(char *patient_name)
{
    delete this->patient_name;
    this->patient_name = new char[strlen(patient_name) + 1];
    strcpy(this->patient_name, patient_name);
    return true;
}
bool patient::set_year(int year)
{
    this->year = year;
    return true;
}
bool patient::set_gender(char *gender)
{
    delete this->gender;
    this->gender = new char[strlen(gender) + 1];
    strcpy(this->gender, gender);
    return true;
}
patient::~patient()
{
    delete patient_id;
    delete patient_name;
    delete gender;
}
bool patient::add_visit_patient(visit *visitPtr)
{
    if (visit_logical_size < visit_physical_size)
    {
        visitsP_arr[visit_logical_size] = visitPtr;
        set_visit_logical_size(visit_logical_size + 1);
    }
    else
    {
        visit_physical_size *= 2;
        visit **temp = new visit *[visit_physical_size];
        for (int i = 0; i < visit_physical_size; i++)
        {
            temp[i] = visitsP_arr[i];
        }
        delete[] visitsP_arr;
        this->visitsP_arr = temp;
        visitsP_arr[visit_logical_size] = visitPtr;
        set_visit_logical_size(visit_logical_size + 1);
    }

    return true;
}

ostream &operator<<(ostream &os, const patient &p)
{
    os << "Patient Details: \n";
    os << "Patient Name: " << p.patient_name << "\n";
    os << "Birth Year: " << p.year << "\n";
    os << "Gender: " << p.gender << "\n";
    os << "Visits Deatils : \n";
    for (int i=0;i<p.visit_logical_size;i++)
    {
        os << "visit "<< i+1 <<" : "<< p.visitsP_arr[i]->get_visit_date()<<"\n";
    }

    return os;
}
