#include <iostream>
using namespace std;
#include <string.h>
#include "researchCenter.h"

researchCenter::researchCenter(const string &researchCenter_name) //
{
    this->researchCenter_name = researchCenter_name;
}

const string &researchCenter::get__researchCenter_name() const
{
    return this->researchCenter_name;
}

const list<researcher *>& researchCenter::get_researcher_arr() const //
{
    return this->researcher_arr;
}
const list<article>& researchCenter::get_articles_arr() const //
{
    return this->articles_arr;
}

bool researchCenter::add_researcher(researcher *researcherToAdd) //
{
    researcher_arr.push_back(researcherToAdd);
    return true;
}

bool researchCenter::add_article(article *articleToAdd) //
{
    articles_arr.push_back(*articleToAdd);
    return true;
}

bool researchCenter::set_researchCenter_name(const string &researchCenter_name)
{
    this->researchCenter_name = researchCenter_name;
    return true;
}

ostream &operator<<(ostream &os, const researchCenter &r) //
{
    os << "----- Research Center ----- \n";
    os << "Research Center Name : \n"
       << r.researchCenter_name << "\n";
    list<researcher *>::const_iterator itr = r.researcher_arr.begin();
    list<researcher *>::const_iterator itrEnd = r.researcher_arr.end();
    os << "----- Research Center Employee List  ----- \n";
    if (itr == itrEnd)
    {
        cout << "Collection is empty!\n";
        return os;
    }
    for (; itr != itrEnd; ++itr)
    {
        os << **itr << "\n";
    }

    return os;
}