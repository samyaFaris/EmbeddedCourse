#include <iostream>
using namespace std;
#include <string.h>
#include "hospital.h"

int hospital::idCount = 0;

hospital::hospital(const char *hospitalName, const char *researchCenterName) : doctor_physical_size(2), doctor_logical_size(0), researchCenterH(researchCenterName),
                                                                               department_logical_size(0), department_physical_size(2), patient_logical_size(0), patient_physical_size(2),
                                                                               visit_logical_size(0), visit_physical_size(2)
{
    this->hospitalName = new char[strlen(hospitalName) + 1];
    strcpy(this->hospitalName, hospitalName);
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
}
char *hospital::get_hospitalName()
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
int hospital::get_doctor_logical_size()
{
    return doctor_logical_size;
}
int hospital::get_doctor_physical_size()
{
    return doctor_physical_size;
}
int hospital::get_department_logical_size()
{
    return department_logical_size;
}
int hospital::get_department_physical_size()
{
    return department_physical_size;
}
int hospital::get_patient_logical_size()
{
    return patient_logical_size;
}
int hospital::get_patient_physical_size()
{
    return patient_physical_size;
}
int hospital::get_visit_logical_size()
{
    return visit_logical_size;
}
int hospital::get_visit_physical_size()
{
    return visit_physical_size;
}
bool hospital::set_doctor_logical_size(int doctor_logical_size)
{
    this->doctor_logical_size = doctor_logical_size;
    return true;
}
bool hospital::set_doctor_physical_size(int doctor_physical_size)
{
    this->doctor_physical_size = doctor_physical_size;
    return true;
}
bool hospital::set_department_logical_size(int department_logical_size)
{
    this->department_logical_size = department_logical_size;
    return true;
}
bool hospital::set_department_physical_size(int department_physical_size)
{
    this->department_physical_size = department_physical_size;
    return true;
}
bool hospital::set_patient_logical_size(int patient_logical_size)
{
    this->patient_logical_size = patient_logical_size;
    return true;
}
bool hospital::set_patient_physical_size(int patient_physical_size)
{
    this->patient_physical_size = patient_physical_size;
    return true;
}
bool hospital::set_visit_logical_size(int visit_logical_size)
{
    this->visit_logical_size = visit_logical_size;
    return true;
}
bool hospital::set_visit_physical_size(int visit_physical_size)
{
    this->visit_physical_size = visit_physical_size;
    return true;
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
    delete[] hospitalName;
}

bool hospital::add_department_to_hospital(const char *departmentName)
{
    for (int i = 0; i < department_logical_size; i++)
    {
        if (strcmp(departmentName, (*(department_arr[i])).get_dep_name()) == 0)
        {
            cout << "Already have department: " << departmentName << "in the hospital, cant add";
            return true;
        }
    }
    department *department_in_hospital = new department(departmentName);
    if (department_logical_size < department_physical_size)
    {
        this->department_arr[department_logical_size] = department_in_hospital;
        set_department_logical_size(department_logical_size + 1);
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
        set_department_logical_size(department_logical_size + 1);
        idCount++;
    }
    return true;
}

bool hospital::add_doctor_to_hospital(const char *doctorName, const char *experties, const char *departmentName)
{
    department *departmentDoctor = nullptr;
    int flag = 0;
    for (int i = 0; i < department_logical_size; i++)
    {
        if (strcmp(departmentName, (*(department_arr[i])).get_dep_name()) == 0)
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
    doctor *doctor_in_hospital = new doctor(doctorName, idCount, experties);
    if (doctor_logical_size < doctor_physical_size)
    {
        doctor_arr[doctor_logical_size] = doctor_in_hospital;
        set_doctor_logical_size(doctor_logical_size + 1);
    }
    else
    {

        doctor_physical_size *= 2;
        doctor **temp = new doctor *[doctor_physical_size];
        for (int i = 0; i < doctor_logical_size; i++)
        {
            temp[i] = doctor_arr[i];
        }
        delete[] doctor_arr;
        this->doctor_arr = temp;
        doctor_arr[doctor_logical_size] = doctor_in_hospital;
        set_department_logical_size(doctor_logical_size + 1);
    }
    departmentDoctor->add_doctor_to_dep(doctor_in_hospital);
    return true;
}

bool hospital::add_patient_to_hospital(const char *patient_id, const char *patient_name, const int year, const char *gender)
{
    for (int i = 0; i < patient_logical_size; i++)
    {
        if (strcmp(patient_arr[i]->get_patient_id(), patient_id) == 0)
        {
            cout << "This patient" << patient_name << " already exists in the hospital.";
            return false;
        }
    }

    patient *patient_in_hospital = new patient(patient_id, patient_name, year, gender);
    if (patient_logical_size < patient_physical_size)
    {
        patient_arr[patient_logical_size] = patient_in_hospital;
        set_patient_logical_size(patient_logical_size + 1);
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
        set_patient_logical_size(patient_logical_size + 1);
    }

    return true;
}

bool hospital::add_visit(const char *visitDate, const char *patientId)
{
    int flag = 0;
    patient *patientVisit = nullptr;
    for (int i = 0; i < patient_logical_size; i++)
    {
        if (strcmp(patientId, patient_arr[i]->get_patient_id()) == 0)
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
            set_visit_logical_size(visit_logical_size + 1);
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
            set_visit_logical_size(visit_logical_size + 1);
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
    os << h.researchCenterH;
    for (int i = 0; i < h.department_logical_size; i++)
    {
        os << *(h.department_arr[i]);
    }
    for (int i = 0; i < h.patient_logical_size; i++)
    {
        os << *(h.patient_arr[i]);
    }

    for(int i=0;i<h.visit_logical_size;i++)
    {
        os << *(h.visit_arr[i]);
    }

    return os;
}
