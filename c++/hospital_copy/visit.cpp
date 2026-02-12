#include <iostream>
using namespace std;
#include <string.h>
#include "visit.h"
#include "patient.h"

visit::visit(const string& visit_date,  patient *patientPtr)
{
    this->visit_date = visit_date;
    this->patientPtr = patientPtr;
}
const string& visit::get_visit_date() const
{
    return visit_date;
}
const patient *visit::get_patientPtr() const
{
    return patientPtr;
}
bool visit::set_visit_date(const string& visit_date)
{

    this->visit_date = visit_date;
    return true;
}
bool visit::set_patientPtr( patient *patientPtr)
{
    this->patientPtr = patientPtr;
    return true;
}

ostream &operator<<(ostream &os, const visit &v)
{
    os << "Visit Details: \n";
    os << "Visit Date: " << v.visit_date << "\n";
    os << "Patient Name: " << v.patientPtr->get_personName() << "\n";
    return os;
}