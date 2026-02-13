#include <iostream>
#include "doctor.h"
#include "doctorResearcher.h"
using namespace std;



doctorResearcher::doctorResearcher(const string& doctor_researcher_name, const string& doctor_researcher_id, int idCounter,const string& experties): 
employee(doctor_researcher_id,doctor_researcher_name,idCounter),
doctor(doctor_researcher_id,doctor_researcher_name,idCounter, experties),
researcher(doctor_researcher_id,doctor_researcher_name,idCounter)
{

}

ostream &operator<<(ostream &os, const doctorResearcher &dr)
{
    os << " -------- doctorResearcher ----------- \n";
    os << (doctor &)dr;
    return os;
}
