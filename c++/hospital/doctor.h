#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
using namespace std;
class department;

class doctor
{
private:
    char *dr_name;
    int worker_id;
    char *experties;
    department* departmentPtr;
    

public:
    const char* get_dr_name() const;
    int get_worker_id() const ;
    department* get_departmentPtr();
    const char *get_worker_experties()const ;
    doctor(const char *name, int workerId, const char *experties);
    doctor(doctor &d);
    bool set_dr_name(char *name);
    bool set_worker_id(int id);
    bool set_worker_experties(char *experties);
    bool set_departmentPtr(department* departmentPtr);
    ~doctor();
    friend ostream &operator<<(ostream &os, const doctor &d);
};

#endif