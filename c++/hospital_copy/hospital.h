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
#include <list>

class hospital
{
private:
    researchCenter researchCenterH;
    string hospitalName;
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
    hospital(const string& hospitalName, const string& researchCenterName);
    const string& get_hospitalName() const;
    doctor **get_doctor_arr();
    department **get_department_arr();
    nurse **get_nurse_arr();
    ~hospital();
    bool add_department_to_hospital(const string& departmentName);
    bool add_doctor_to_hospital(const string& doctorName, const string& doctorId, const string& experties, const string& departmentName);
    bool add_nurse_to_hospital(const string& nurseName, const string& nurseId, int experienceYears, const string& departmentName);
    bool add_researcher_to_hospital(const string& researchert_name, const string& researcher_id);
    bool add_doctor_researcher_to_hospital(const string& researchert_name, const string& researcher_id,const string& experties, const string& departmentName);
    bool add_patient_to_hospital(const string& patient_id, const string& patient_name, const int year, const string& gender);
    bool add_visit(const string& visitDate, const string& patientId);
    bool add_article( const string& pupDate, const string& articleName, const string& magazineName, const string& researcherId);
    friend ostream &operator<<(ostream &os, const hospital &h);
};
#endif