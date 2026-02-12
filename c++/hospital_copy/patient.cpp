#include <iostream>
using namespace std;
#include <string.h>
#include "patient.h"
#include "visit.h"

patient::patient(const string &personId, const string &personName, int year, const string &gender) : person(personId, personName), visit_logical_size(0), visit_physical_size(2)
{
    this->year = year;
    this->gender = gender;
    this->visitsP_arr = new visit *[visit_physical_size];
    for (int i = 0; i < visit_physical_size; i++)
    {
        visitsP_arr[i] = nullptr;
    }
}

int patient::get_year() const
{
    return this->year;
}
const string &patient::get_gender() const
{
    return this->gender;
}

bool patient::set_year(int year)
{
    this->year = year;
    return true;
}
bool patient::set_gender(const string &gender)
{
    this->gender = gender;
    return true;
}

visit **patient::get_visitP() const
{
    return this->visitsP_arr;
}

bool patient::add_visit_patient(visit *visitPtr)
{
    if (visit_logical_size < visit_physical_size)
    {
        visitsP_arr[visit_logical_size] = visitPtr;
        visit_logical_size++;
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
        visit_logical_size++;
    }

    return true;
}

ostream &operator<<(ostream &os, const patient &p)
{
    os << "Patient Details: \n";
    // os << "Patient Name: " << p.patient_name << "\n";
    os << (person &)p;
    os << "Birth Year: " << p.year << "\n";
    os << "Gender: " << p.gender << "\n";
    os << "Visits Deatils : \n";
    for (int i = 0; i < p.visit_logical_size; i++)
    {
        os << "visit " << i + 1 << " : " << p.visitsP_arr[i]->get_visit_date() << "\n";
    }

    return os;
}
