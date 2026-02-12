#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <iostream>
#include <string.h>
using namespace std;

class article
{
private:
    string pupDate;
    string articleName;
    string magazineName;

public:
    article(const string& pupDate, const string& articleName, const string& magazineName);
    const string& get_pupDate()const;
    const string& get_articleName()const;
    const string& get_magazineName()const;
    bool set_pupDate(const string& pupDate);
    bool set_magazineName(const string& magazineName);
    bool set_articleName(const string& articleName);
    friend ostream &operator<<(ostream &os, const article &a);
};

#endif