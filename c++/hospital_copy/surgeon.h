#ifndef __SURGEON_H
#define __SURGEON_H
#include <iostream>
#include "doctor.h"
using namespace std;
class department;

class surgeon :   public doctor
{

private:

int numberOfSurgeries;

public:
    surgeon(const string& doctorName, const string& doctorId, int idCount,const string& experties, int numberOfSurgeries);
    int get_numberOfSurgeries()const;
    bool set_numberOfSurgeries(const int numberOfSurgeries);
    friend ostream &operator<<(ostream &os, const surgeon &s);
};

#endif