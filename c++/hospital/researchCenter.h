#ifndef __RESEARCH_H
#define __RESEARCH_H
#include <iostream>
using namespace std;

class researchCenter
{
private:
    char *researchCenter_name;

public:
    researchCenter(const char *researchCenter_name);
    char *get__researchCenter_name();
    bool set_researchCenter_name(char *researchCenter_name);
    ~researchCenter();
    friend ostream &operator<<(ostream &os, const researchCenter &r);
};

#endif