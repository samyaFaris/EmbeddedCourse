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
#include "surgeon.h"
#include <list>

class hospital
{
private:
    researchCenter researchCenterH;
    string hospitalName;
    static int idCount;
    list<department> department_arr;
    list<patient> patient_arr;
    list<visit> visit_arr;
    list <employee *> employee_arr;
    // employee **employee_arr;
    // int employee_logical_size;
    // int employee_physical_size;


public:
    hospital(const string &hospitalName, const string &researchCenterName);
    const string &get_hospitalName() const;
    const list<department> &get_department_arr();
    bool add_department_to_hospital(const string &departmentName);
    bool add_doctor_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName);
    bool add_surgeon_to_hospital(const string &doctorName, const string &doctorId, const string &experties, const string &departmentName, int numberOfSurgeries);
    bool add_nurse_to_hospital(const string &nurseName, const string &nurseId, int experienceYears, const string &departmentName);
    bool add_researcher_to_hospital(const string &researchert_name, const string &researcher_id);
    bool add_doctor_researcher_to_hospital(const string &researchert_name, const string &researcher_id, const string &experties, const string &departmentName);
    bool add_patient_to_hospital(const string &patient_id, const string &patient_name, const int year, const string &gender);
    bool add_visit(const string &visitDate, const string &patientId);
    bool add_article(const string &pupDate, const string &articleName, const string &magazineName, const string &researcherId);
    friend ostream &operator<<(ostream &os, const hospital &h);
    patient *find_patient_byId(const string &patient_id);
    department *check_department_exist(const string &departmentName);
};
#endif