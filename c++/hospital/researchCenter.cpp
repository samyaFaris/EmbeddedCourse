#include <iostream>
using namespace std;
#include <string.h>
#include "researchCenter.h"

researchCenter::researchCenter(const char *researchCenter_name)
{
    this->researchCenter_name = new char[strlen(researchCenter_name)+1];
    strcpy(this->researchCenter_name, researchCenter_name);
}
char *researchCenter::get__researchCenter_name()
{
    return this->researchCenter_name;
}
bool researchCenter::set_researchCenter_name(char *researchCenter_name)
{
    delete this->researchCenter_name;
    this->researchCenter_name = new char[strlen(researchCenter_name)+1];
    strcpy(this->researchCenter_name, researchCenter_name);
    return true;
}
researchCenter::~researchCenter()
{
    delete [] researchCenter_name;
}
ostream &operator<<(ostream &os, const researchCenter &r)
{
    os << "Research Center : " << r.researchCenter_name<< "\n" ;
    return os;
}