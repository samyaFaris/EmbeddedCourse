#include <iostream>
using namespace std;
#include <string.h>
#include "article.h"

article::article(const string& pupDate, const string& articleName, const string& magazineName)
{
    this->pupDate = pupDate ;
    this->articleName = articleName;
    this->magazineName = magazineName;
    
}

 const string& article::get_pupDate()const
{
    return this->pupDate;
}
const string& article::get_articleName()const
{
    return this->articleName;
}
const string& article::get_magazineName()const
{
    return this->magazineName;
}
bool article::set_pupDate(const string& pupDate)
{
    
    this->pupDate = pupDate;
    return true;
}
bool article::set_magazineName(const string& magazineName)
{
    this->magazineName = magazineName;
    
    return true;
}
bool article::set_articleName(const string& articleName)
{
    this->articleName = articleName;
    return true;
}

ostream &operator<<(ostream &os, const article &a)
{
    os << "------ Article Details ------\n";
    os << "Date : "<< a.pupDate << "\n";
    os << "Name : " << a.articleName << "\n";
    os << "Magazine Name : " << a.magazineName << "\n";
    return os;
}