#include <iostream>
using namespace std;
#include <string.h>
#include "hospital.h"

int hospital::idCount = 0;

hospital::hospital(const string &hospitalName, const string &researchCenterName) : doctor_physical_size(2), doctor_logical_size(0), researchCenterH(researchCenterName),
                                                                                   department_logical_size(0), department_physical_size(2), patient_logical_size(0), patient_physical_size(2),
                                                                                   visit_logical_size(0), visit_physical_size(2), nurse_logical_size(0), nurse_physical_size(2),
                                                                                   employee_logical_size(0), employee_physical_size(2)
{
    this->hospitalName = hospitalName;
    this->doctor_arr = new doctor *[doctor_physical_size];
    for (int i = 0; i < doctor_physical_size; i++)
    {
        this->doctor_arr[i] = nullptr;
    }
    this->department_arr = new department *[department_physical_size];
    for (int i = 0; i < department_physical_size; i++)
    {
        this->department_arr[i] = nullptr;
    }
    this->patient_arr = new patient *[patient_physical_size];
    for (int i = 0; i < patient_physical_size; i++)
    {
        this->patient_arr[i] = nullptr;
    }
    this->visit_arr = new visit *[visit_physical_size];
    for (int i = 0; i < visit_physical_size; i++)
    {
        this->visit_arr[i] = nullptr;
    }
    this->nurse_arr = new nurse *[nurse_physical_size];
    for (int i = 0; i < nurse_physical_size; i++)
    {
        this->nurse_arr[i] = nullptr;
    }
    this->employee_arr = new employee *[employee_physical_size];
    for (int i = 0; i < employee_physical_size; i++)
    {
        this->employee_arr[i] = 0;
    }
}
const string &hospital::get_hospitalName() const
{
    return this->hospitalName;
}
doctor **hospital::get_doctor_arr()
{
    return this->doctor_arr;
}
department **hospital::get_department_arr()
{
    return this->department_arr;
}
nurse **hospital::get_nurse_arr()
{
    return this->nurse_arr;
}

hospital::~hospital()
{
    for (int i = 0; i < doctor_logical_size; i++)
    {
        delete doctor_arr[i];
    }
    for (int i = 0; i < department_logical_size; i++)
    {
        delete department_arr[i];
    }

    delete[] doctor_arr;
    delete[] department_arr;
}

bool hospital::add_department_to_hospital(const string &departmentName)
{
    for (int i = 0; i < department_logical_size; i++)
    {
        if (departmentName == department_arr[i]->get_dep_name())
        {
            cout << "Already have department: " << departmentName << "in the hospital, cant add";
            return true;
        }
    }
    department *department_in_hospital = new department(departmentName);
    if (department_logical_size < department_physical_size)
    {
        this->department_arr[department_logical_size] = department_in_hospital;
        department_logical_size++;
    }
    else
    {

        department_physical_size *= 2;
        department **temp = new department *[department_physical_size];
        for (int i = 0; i < department_logical_size; i++)
        {
            temp[i] = department_arr[i];
        }
        delete[] department_arr;
        this->department_arr = temp;
        department_arr[department_logical_size] = department_in_hospital;
        department_logical_size++;
        idCount++;
    }
    return true;
}

bool hospital::add_doctor_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName)
{
    department *departmentDoctor = nullptr;
    int flag = 0;
    for (int i = 0; i < department_logical_size; i++)
    {
        if (departmentName == department_arr[i]->get_dep_name())
        {
            flag = 1;
            departmentDoctor = department_arr[i];
            break;
        }
    }
    if (flag == 0)
    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }
    idCount++;
    doctor *doctor_in_hospital = new doctor(doctorId, doctorName, idCount, experties);

    if (employee_logical_size < employee_physical_size)
    {
        employee_arr[employee_logical_size] = doctor_in_hospital;
        employee_logical_size++;
    }
    else
    {
        employee_physical_size *= 2;
        employee **temp = new employee *[employee_physical_size];
        for (int i = 0; i < employee_logical_size; i++)
        {
            temp[i] = employee_arr[i];
        }
        delete[] employee_arr;
        this->employee_arr = temp;
        employee_arr[employee_logical_size] = doctor_in_hospital;
        employee_logical_size++;
    }

    departmentDoctor->add_doctor_to_dep(doctor_in_hospital);
    return true;
}

bool hospital::add_researcher_to_hospital(const string &researcher_name, const string &researcher_id)
{

    idCount++;
    researcher *researcher_in_hospital = new researcher(researcher_name, researcher_id, idCount);
    if (employee_logical_size < employee_physical_size)
    {
        employee_arr[employee_logical_size] = researcher_in_hospital;
        employee_logical_size++;
    }
    else
    {
        employee_physical_size *= 2;
        employee **temp = new employee *[employee_physical_size];
        for (int i = 0; i < employee_logical_size; i++)
        {
            temp[i] = employee_arr[i];
        }
        delete[] employee_arr;
        this->employee_arr = temp;
        employee_arr[employee_logical_size] = researcher_in_hospital;
        employee_logical_size++;
    }
    this->researchCenterH.add_researcher(researcher_in_hospital);
    return true;
}
bool hospital::add_article(const string &pupDate, const string &articleName, const string &magazineName, const string &researcherId) ///////////////////
{
    researcher *researcher_article = nullptr;
    int flag = 0;
    list<researcher *>::const_iterator itr = researchCenterH.get_researcher_arr().begin();
    list<researcher *>::const_iterator itrEnd = researchCenterH.get_researcher_arr().end();

    // cout << "**************************";
    // cout << researchCenterH.get_researcher_arr().size();
    if (itr == itrEnd)
    {
        cout << "Collection is empty!\n";
        return false;
    }
    for (; itr != itrEnd; ++itr)
    {
        if (researcherId == (*itr)->get_person_id())
        {
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
    department *departmentDoctor = nullptr;
    int flag = 0;
    for (int i = 0; i < department_logical_size; i++)
    {
        if (departmentName == (*(department_arr[i])).get_dep_name())
        {
            flag = 1;
            departmentDoctor = department_arr[i];
        }
    }
    if (flag == 0)
    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }

    doctorResearcher *dr = new doctorResearcher(doctor_researcher_name, doctor_researcher_id, idCount, experties);
    if (employee_logical_size < employee_physical_size)
    {
        employee_arr[employee_logical_size] = dr;
        employee_logical_size++;
    }
    else
    {
        employee_physical_size *= 2;
        employee **temp = new employee *[employee_physical_size];
        for (int i = 0; i < employee_logical_size; i++)
        {
            temp[i] = employee_arr[i];
        }
        delete[] employee_arr;
        this->employee_arr = temp;
        employee_arr[employee_logical_size] = dr;
        employee_logical_size++;
    }
    dr->set_departmentPtr(departmentDoctor);
    this->researchCenterH.add_researcher(dr);
    departmentDoctor->add_doctor_to_dep(dr);
    return true;
}

bool hospital::add_nurse_to_hospital(const string &nurseName, const string &nurseId, int experienceYears, const string &departmentName)
{
    department *departmentNurse = nullptr;
    int flag = 0;
    for (int i = 0; i < department_logical_size; i++)
    {
        if (departmentName == (*(department_arr[i])).get_dep_name())
        {
            flag = 1;
            departmentNurse = department_arr[i];
        }
    }
    if (flag == 0)
    {
        cout << "The hospital dosent department: " << departmentName << "cant add this doctor to our hospita";
        return false;
    }

    nurse *nurse_in_hospital = new nurse(nurseId, nurseName, idCount, experienceYears);
    idCount++;

    if (employee_logical_size < employee_physical_size)
    {
        employee_arr[employee_logical_size] = nurse_in_hospital;
        employee_logical_size++;
    }
    else
    {
        employee_physical_size *= 2;
        employee **temp = new employee *[employee_physical_size];
        for (int i = 0; i < employee_logical_size; i++)
        {
            temp[i] = employee_arr[i];
        }
        delete[] employee_arr;
        this->employee_arr = temp;
        employee_arr[employee_logical_size] = nurse_in_hospital;
        employee_logical_size++;
    }
    departmentNurse->add_nurse_to_dep(nurse_in_hospital);
    return true;
}

bool hospital::add_patient_to_hospital(const string &patient_id, const string &patient_name, const int year, const string &gender)
{
    for (int i = 0; i < patient_logical_size; i++)
    {
        if (patient_arr[i]->get_person_id() == patient_id)
        {
            cout << "This patient" << patient_name << " already exists in the hospital.";
            return false;
        }
    }
    patient *patient_in_hospital = new patient(patient_id, patient_name, year, gender);
    if (patient_logical_size < patient_physical_size)
    {
        patient_arr[patient_logical_size] = patient_in_hospital;
        patient_logical_size++;
    }
    else
    {
        patient_physical_size *= 2;
        patient **temp = new patient *[patient_physical_size];
        for (int i = 0; i < patient_physical_size; i++)
        {
            temp[i] = patient_arr[i];
        }
        delete[] patient_arr;
        this->patient_arr = temp;
        patient_arr[patient_logical_size] = patient_in_hospital;
        patient_logical_size++;
    }

    return true;
}

bool hospital::add_visit(const string &visitDate, const string &patientId)
{
    int flag = 0;
    patient *patientVisit = nullptr;
    for (int i = 0; i < patient_logical_size; i++)
    {
        if (patientId == patient_arr[i]->get_person_id())
        {
            flag = 1;
            patientVisit = patient_arr[i];
        }
    }
    if (flag == 1)
    {
        visit *visit_in_hospital = new visit(visitDate, patientVisit);
        if (visit_logical_size < visit_physical_size)
        {
            visit_arr[visit_logical_size] = visit_in_hospital;
            visit_logical_size++;
        }
        else
        {
            visit_physical_size *= 2;
            visit **temp = new visit *[visit_physical_size];
            for (int i = 0; i < visit_physical_size; i++)
            {
                temp[i] = visit_arr[i];
            }
            delete[] visit_arr;
            this->visit_arr = temp;
            visit_arr[visit_logical_size] = visit_in_hospital;
            visit_logical_size++;
        }
        patientVisit->add_visit_patient(visit_in_hospital);

        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const hospital &h)
{
    os << "Hospital Details \n";
    os << "name: " << h.hospitalName << "\n";
    for (int i = 0; i < h.department_logical_size; i++)
    {
        os << *(h.department_arr[i]);
    }
    os << h.researchCenterH;
    for (int i = 0; i < h.patient_logical_size; i++)
    {
        os << *(h.patient_arr[i]);
    }

    for (int i = 0; i < h.visit_logical_size; i++)
    {
        os << *(h.visit_arr[i]);
    }

    return os;
}
