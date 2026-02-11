#ifndef __RESEARCH_H
#define __RESEARCH_H
#include <iostream>
using namespace std;
#include "researcher.h"

class researchCenter
{
private:
    char *researchCenter_name;
    researcher ** researcher_arr;
    int researcher_logical_size;
    int researcher_physical_size;


public:
    researchCenter(const char *researchCenter_name);
    char *get__researchCenter_name();
    bool set_researchCenter_name(char *researchCenter_name);
    int get_researcher_logical_size();
    int get_researcher_physical_size();
    bool set_researcher_logical_size(int researcher_logical_size);
    bool set_researcher_physical_size(int researcher_physical_size);
    researcher ** get_researcher_arr();
    bool add_researcher(researcher* researcherToAdd);
    ~researchCenter();
    friend ostream &operator<<(ostream &os, const researchCenter &r);
};

#endif