#include <iostream>
using namespace std;
#include <string.h>
#include "visit.h"
#include "patient.h"

visit::visit(const char *visit_date, const patient *patientPtr)
{
    this->visit_date = new char[strlen(visit_date)];
    strcpy(this->visit_date, visit_date);
    this->patientPtr = patientPtr;
}
char *visit::get_visit_date()
{
    return visit_date;
}
const patient *visit::get_patientPtr()
{
    return patientPtr;
}
bool visit::set_visit_date(char *visit_date)
{
    delete[] visit_date;
    this->visit_date = new char[strlen(visit_date)];
    strcpy(this->visit_date, visit_date);
    return true;
}
visit::~visit()
{
    delete [] visit_date;
}
ostream &operator<<(ostream &os, const visit &v)
{
    os << "Visit Details: \n";
    os << "Visit Date: " << v.visit_date << "\n";
    os << "Patient Name: " << v.patientPtr->get_patient_name() << "\n";
    return os;

}