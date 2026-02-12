#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#include "doctor.h"
#include "department.h"
#include "researchCenter.h"
#include "patient.h"
#include "visit.h"
#include "nurse.h"
#include "researcher.h"
#include "article.h"
#include "doctorResearcher.h"

class hospital
{
private:
    researchCenter researchCenterH;
    char *hospitalName;
    static int idCount;
    doctor **doctor_arr;
    department **department_arr;
    patient **patient_arr;
    visit **visit_arr;
    nurse **nurse_arr;
    employee** employee_arr;  
    int employee_logical_size;
    int employee_physical_size;
    int doctor_logical_size;
    int doctor_physical_size;
    int department_logical_size;
    int department_physical_size;
    int patient_logical_size;
    int patient_physical_size;
    int visit_logical_size;
    int visit_physical_size;
    int nurse_logical_size;
    int nurse_physical_size;

public:
    hospital(const char *hospitalName, const char *researchCenterName);
    char *get_hospitalName();
    doctor **get_doctor_arr();
    department **get_department_arr();
    nurse **get_nurse_arr();
    int get_doctor_logical_size();
    int get_doctor_physical_size();
    int get_department_logical_size();
    int get_department_physical_size();
    int get_patient_logical_size();
    int get_patient_physical_size();
    int get_visit_logical_size();
    int get_visit_physical_size();
    int get_nurse_logical_size();
    int get_nurse_physical_size();
    bool set_doctor_logical_size(int doctor_logical_size);
    bool set_doctor_physical_size(int doctor_physical_size);
    bool set_department_logical_size(int department_logical_size);
    bool set_department_physical_size(int department_physical_size);
    bool set_patient_logical_size(int patient_logical_size);
    bool set_patient_physical_size(int patient_physical_size);
    bool set_visit_logical_size(int visit_logical_size);
    bool set_visit_physical_size(int visit_physical_size);
    bool set_nurse_logical_size(int visit_logical_size);
    bool set_nurse_physical_size(int visit_physical_size);
    ~hospital();
    bool add_department_to_hospital(const char *departmentName);
    bool add_doctor_to_hospital(const char *doctorName, const char *doctorId, const char *experties, const char *departmentName);
    bool add_nurse_to_hospital(const char *nurseName, const char *nurseId, int experienceYears, const char *departmentName);
    bool add_researcher_to_hospital(const char *researchert_name, const char *researcher_id);
    bool add_doctor_researcher_to_hospital(const char *researchert_name, const char *researcher_id,const char *experties, const char *departmentName);
    bool add_patient_to_hospital(const char *patient_id, const char *patient_name, const int year, const char *gender);
    bool add_visit(const char *visitDate, const char *patientId);
    bool add_article( const char *pupDate, const char *articleName, const char *magazineName, const char* researcherId);
    friend ostream &operator<<(ostream &os, const hospital &h);
};
#endif