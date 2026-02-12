#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include <iostream>
using namespace std;
#include "employee.h"
#include "article.h"
#include <string.h>
#include <list>


class researcher : virtual public employee
{
protected:

    list<article> articles;


public:
    
    researcher(const string& rName, const string& rId, int idCounter);
    list<article> get_articles() const;
    bool add_article_to_researcher(article *articlePtr);
    friend ostream &operator<<(ostream &os, const researcher &r);
};
#endif