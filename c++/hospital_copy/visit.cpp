#include <iostream>
using namespace std;
#include <string.h>
#include "visit.h"
#include "patient.h"
#include "department.h"

visit::visit(const string &visit_date, patient *patientPtr,string visit_purpose,department *depPtr,  employee * employeePtr)
{
    this->visit_date = visit_date;
    this->patientPtr = patientPtr;
    this->visit_purpose=visit_purpose;
    this->depPtr=depPtr;
    this->employeePtr=employeePtr;
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
    os << "Visit Purpose: " << v.visit_purpose << "\n";
    os << "Department Name: " <<v.depPtr->get_dep_name() << "\n";
    os << "In charge Employee: " << v.employeePtr->get_person_id() << "\n";
    return os;
}