#include <iostream>
#include "doctor.h"
#include "doctorResearcher.h"
using namespace std;

doctorResearcher::doctorResearcher(const doctor &d, const researcher &r) : employee(person(d.get_person_id(), d.get_personName()), d.get_workerId()),
                                                                           doctor(d), researcher(r)
{
}
