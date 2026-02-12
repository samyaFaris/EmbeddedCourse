#include <iostream>
#include "doctor.h"
#include "doctorResearcher.h"
using namespace std;

// doctorResearcher::doctorResearcher(const doctor &d, const researcher &r) : employee(person(d.get_person_id(), d.get_personName()), d.get_workerId()),
//                                                                            doctor(d), researcher(r)
// {
// }

// // doctorResearcher::doctorResearcher(doctor&& d, researcher&& r)
// //     : employee(person(d.get_person_id(), d.get_personName()), d.get_workerId()),
// //       doctor(std::move(d)),
// //       researcher(std::move(r))
// // {
// // }

doctorResearcher::doctorResearcher(const char *doctor_researcher_name, const char *doctor_researcher_id, int idCounter,const char *experties): 
employee(doctor_researcher_id,doctor_researcher_name,idCounter),
doctor(doctor_researcher_id,doctor_researcher_name,idCounter, experties),
researcher(doctor_researcher_id,doctor_researcher_name,idCounter)
{

}

ostream &operator<<(ostream &os, const doctorResearcher &dr)
{
    os << " -------- doctorResearcher -----------";
    os << "**********Doctor: \n";
    os << (doctor &)dr;
    // os << "**********Researcher: \n";
    // os << (researcher &)dr;
    return os;
}
