#include <iostream>
using namespace std;
#include "surgeon.h"
#include <string.h>

surgeon::surgeon(const string &doctorName, const string &doctorId, int idCount, const string &experties, int numberOfSurgeries) : employee(doctorName, doctorId, idCount),
                                                                                                                                  doctor(doctorName, doctorId, idCount, experties)
{
    this->numberOfSurgeries = numberOfSurgeries;
}

int surgeon::get_numberOfSurgeries() const
{
    return this->numberOfSurgeries;
}
bool surgeon::set_numberOfSurgeries(const int numberOfSurgeries)
{
    this->numberOfSurgeries = numberOfSurgeries;
    return true;
}

ostream &operator<<(ostream &os, const surgeon &s)
{
    os << "--------- SURGEON DETAILS --------- \n";
    os << (doctor &)s;
    os<< "Number Of Surgeries : " << s.numberOfSurgeries;
    return os;
}