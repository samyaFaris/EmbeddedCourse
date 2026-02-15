#include <iostream>
using namespace std;
#include <string.h>
#include "patient.h"
#include "visit.h"
#include "surgerieVisit.h"


patient::patient(const string &personId, const string &personName, int year, const string &gender) : person(personId, personName) // 
{
    this->year = year;
    this->gender = gender;
 
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

const list <visit*>& patient::get_visitP() const //
{
    return this->visitsP_arr;
}

bool patient::add_visit_patient(visit *visitPtr)
{
    visitsP_arr.push_back(visitPtr);
    return true;
}

ostream &operator<<(ostream &os, const patient &p) //
{
    os << "----------------Patient Details: ----------------\n";
    // os << "Patient Name: " << p.patient_name << "\n";
    os << (person &)p;
    os << "Birth Year: " << p.year << "\n";
    os << "Gender: " << p.gender << "\n";
    os << "--------Visits List  : --------\n";
    list<visit *>::const_iterator itr = p.visitsP_arr.begin();
    list<visit *>::const_iterator itrEnd = p.visitsP_arr.end();
    if (itr == itrEnd)
    {
        return os;
    }
    for (; itr != itrEnd; ++itr)
    {
    if (typeid(**itr) == typeid(surgerieVisit))
      {
         os << (surgerieVisit&)(**itr);
      }
      else 
      {
        os << (**itr) << "\n";

      }
    }

    return os;
}
