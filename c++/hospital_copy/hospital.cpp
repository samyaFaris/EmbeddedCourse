#include <iostream>
using namespace std;
#include <string.h>
#include "hospital.h"

int hospital::idCount = 0;

hospital::hospital(const string &hospitalName, const string &researchCenterName) : researchCenterH(researchCenterName)
{
    this->hospitalName = hospitalName;
}
const string &hospital::get_hospitalName() const
{
    return this->hospitalName;
}

const list<department> &hospital::get_department_arr()
{
    return this->department_arr;
}

department *hospital::check_department_exist(const string &departmentName)
{

    list<department>::iterator itr = this->department_arr.begin();
    list<department>::iterator itrEnd = this->department_arr.end();
    for (; itr != itrEnd; ++itr)
    {
        if (departmentName == itr->get_dep_name())
        {
            return &(*itr);
        }
    }
    return nullptr;
}

bool hospital::add_department_to_hospital(const string &departmentName)
{

    if (check_department_exist(departmentName) == nullptr) // department dosnt exist
    {
        department *department_in_hospital = new department(departmentName);
        department_arr.push_back(*department_in_hospital);
        return true;
    }
    return false;
}

bool hospital::add_doctor_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName)
{
    department *departmentDoctor = check_department_exist(departmentName);
    if (departmentDoctor == nullptr)
    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }
    idCount++;
    doctor *doctor_in_hospital = new doctor(doctorId, doctorName, idCount, experties);
    departmentDoctor->add_doctor_to_dep(doctor_in_hospital);
    this->employee_arr.push_back(doctor_in_hospital);
    return true;
}
bool hospital::add_surgeon_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName, int numberOfSurgeries)
{
    department *departmentDoctor = check_department_exist(departmentName);
    if (departmentDoctor == nullptr)
    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }
    idCount++;
    surgeon *surgeon_in_hospital = new surgeon(doctorId, doctorName, idCount, experties, numberOfSurgeries);
    departmentDoctor->add_doctor_to_dep(surgeon_in_hospital);
    this->employee_arr.push_back(surgeon_in_hospital);
    return true;
}

bool hospital::add_researcher_to_hospital(const string &researcher_name, const string &researcher_id)
{

    idCount++;
    researcher *researcher_in_hospital = new researcher(researcher_name, researcher_id, idCount);
    this->researchCenterH.add_researcher(researcher_in_hospital);
    this->employee_arr.push_back(researcher_in_hospital);
    return true;
}
bool hospital::add_article(const string &pupDate, const string &articleName, const string &magazineName, const string &researcherId) ///////////////////
{
    researcher *researcher_article = nullptr;
    int flag = 0;
    list<researcher *>::const_iterator itr = researchCenterH.get_researcher_arr().begin();
    list<researcher *>::const_iterator itrEnd = researchCenterH.get_researcher_arr().end();
    for (; itr != itrEnd; ++itr)
    {
        if (researcherId == (*itr)->get_person_id())
        {
            cout << (*itr)->get_person_id() << "\n";
            researcher_article = *itr;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Cant add this aticle, researcher doesnt exist";
        return false;
    }
    article *articleToAdd = new article(pupDate, articleName, magazineName);
    researcher_article->add_article_to_researcher(articleToAdd);
    this->researchCenterH.add_article(articleToAdd);
    return true;
}

bool hospital::add_doctor_researcher_to_hospital(const string &doctor_researcher_name, const string &doctor_researcher_id, const string &experties, const string &departmentName)
{
    department *departmentDoctor = check_department_exist(departmentName);
    if (departmentDoctor == nullptr)
    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }

    doctorResearcher *dr = new doctorResearcher(doctor_researcher_name, doctor_researcher_id, idCount, experties);
    dr->set_departmentPtr(departmentDoctor);
    this->researchCenterH.add_researcher(dr);
    departmentDoctor->add_doctor_to_dep(dr);
    this->employee_arr.push_back(dr);
    return true;
}

bool hospital::add_nurse_to_hospital(const string &nurseName, const string &nurseId, int experienceYears, const string &departmentName)
{

    department *departmentNurse = check_department_exist(departmentName);
    if (departmentNurse == nullptr)

    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }
    nurse *nurse_in_hospital = new nurse(nurseId, nurseName, idCount, experienceYears);
    departmentNurse->add_nurse_to_dep(nurse_in_hospital);
    this->employee_arr.push_back(nurse_in_hospital);
    return true;
}
patient *hospital::find_patient_byId(const string &patient_id)
{

    list<patient>::iterator itr = this->patient_arr.begin();
    list<patient>::iterator itrEnd = this->patient_arr.end();
    for (; itr != itrEnd; ++itr)
    {
        if (patient_id == itr->get_person_id())
        {
            return &(*itr);
        }
    }
    return nullptr;
}
bool hospital::add_patient_to_hospital(const string &patient_id, const string &patient_name, const int year, const string &gender)
{

    if (find_patient_byId(patient_id) != nullptr)
    {
        cout << "This patient : " << patient_name << " already exists in the hospital.\n";
        return false;
    }

    patient *patient_in_hospital = new patient(patient_id, patient_name, year, gender);
    this->patient_arr.push_back(*patient_in_hospital);

    return true;
}

bool hospital::add_visit(const string &visitDate, const string &patientId)
{
    patient *patientVisit = find_patient_byId(patientId);
    if (patientVisit == nullptr)
    {
        cout << "The patient dos'nt exist in the hospital, cant add the visit.";
        return false;
    }
    visit *visit_in_hospital = new visit(visitDate, patientVisit);
    patientVisit->add_visit_patient(visit_in_hospital);
    visit_arr.push_back(visit_in_hospital);

    return true;
}

bool hospital::add_surgerieVisit(const string &visitDate, const string &patientId, int numSurgerieRoom, bool isFasting)
{
    patient *patientVisit = find_patient_byId(patientId);
    if (patientVisit == nullptr)
    {
        cout << "The patient dos'nt exist in the hospital, cant add the visit.";
        return false;
    }
    surgerieVisit *visit_in_hospital = new surgerieVisit(visitDate, patientVisit, numSurgerieRoom, isFasting);
    patientVisit->add_visit_patient(visit_in_hospital);
    visit_arr.push_back(visit_in_hospital);
    return true;
}

ostream &operator<<(ostream &os, const hospital &h)
{
    os << "Hospital Details \n";
    os << "name: " << h.hospitalName << "\n";
    list<department>::const_iterator itr = h.department_arr.begin();
    list<department>::const_iterator itrEnd = h.department_arr.end();
    for (; itr != itrEnd; ++itr)
    {
        os << *itr;
    }
    os << h.researchCenterH;
    list<patient>::const_iterator itrP = h.patient_arr.begin();
    list<patient>::const_iterator itrEndP = h.patient_arr.end();
    for (; itrP != itrEndP; ++itrP)
    {
        os << *itrP;
    }

    return os;
}
