#include <iostream>
using namespace std;
#include <string.h>
#include "researchCenter.h"

researchCenter::researchCenter(const char *researchCenter_name) : researcher_logical_size(0), researcher_physical_size(2)
{
    this->researchCenter_name = new char[strlen(researchCenter_name) + 1];
    strcpy(this->researchCenter_name, researchCenter_name);
    this->researcher_arr = new researcher *[researcher_physical_size];
    for (int i = 0; i < researcher_physical_size; i++)
    {
        researcher_arr[i] = nullptr;
    }
}

char *researchCenter::get__researchCenter_name()
{
    return this->researchCenter_name;
}
int researchCenter::get_researcher_logical_size()
{
    return this->researcher_logical_size;
}
int researchCenter::get_researcher_physical_size()
{
    return this->researcher_physical_size;
}
bool researchCenter::set_researcher_logical_size(int researcher_logical_size)
{
    this->researcher_logical_size = researcher_logical_size;
    return true;
}
bool researchCenter::set_researcher_physical_size(int researcher_physical_size)
{
    this->researcher_physical_size = researcher_physical_size;
    return true;
}
researcher **researchCenter::get_researcher_arr()
{
    return this->researcher_arr;
}

bool researchCenter::add_researcher(researcher *researcherToAdd)
{
    if (researcher_logical_size < researcher_physical_size)
    {

        this->researcher_arr[researcher_logical_size] = researcherToAdd;
        set_researcher_logical_size(researcher_logical_size + 1);
    }
    else if (researcher_logical_size == researcher_physical_size)
    {
        researcher_physical_size *= 2;
        researcher **temp = new researcher *[researcher_physical_size];
        for (int i = 0; i < researcher_logical_size; i++)
        {
            temp[i] = researcher_arr[i];
        }
        delete[] researcher_arr;
        this->researcher_arr = temp;
        researcher_arr[researcher_logical_size] = researcherToAdd;
        set_researcher_logical_size(researcher_logical_size + 1);
    }
    return true;
}

bool researchCenter::set_researchCenter_name(char *researchCenter_name)
{
    delete this->researchCenter_name;
    this->researchCenter_name = new char[strlen(researchCenter_name) + 1];
    strcpy(this->researchCenter_name, researchCenter_name);
    return true;
}
researchCenter::~researchCenter()
{
    delete[] researchCenter_name;
}
ostream &operator<<(ostream &os, const researchCenter &r)
{
   os << "----- Research Center ----- \n";
    os << "Research Center Name : " << r.researchCenter_name << "\n";
    os << "----- Research Center Employee List  ----- \n";
    for (int i=0;i<r.researcher_logical_size;i++)
    {
        os<<*r.researcher_arr[i]<<"\n";
    }
    
    return os;
}