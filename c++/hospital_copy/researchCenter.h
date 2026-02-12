#ifndef __RESEARCH_H
#define __RESEARCH_H
#include <iostream>
using namespace std;
#include "researcher.h"
#include "article.h"
#include <string.h>
#include <list>

class researchCenter
{
private:
    string researchCenter_name;
    // researcher **researcher_arr;
    list<researcher*> researcher_arr;
    list<article> articles_arr;
    // int researcher_logical_size;
    // int researcher_physical_size;
    // int article_logical_size;
    // int article_physical_size;

public:
    researchCenter(const string &researchCenter_name);
    const string &get__researchCenter_name() const;
    bool set_researchCenter_name(const string &researchCenter_name);
    const list<researcher*>& get_researcher_arr() const; //
    const list<article>& get_articles_arr() const;
    bool add_researcher(researcher *researcherToAdd);
    bool add_article(article *articleToAdd);
    friend ostream &operator<<(ostream &os, const researchCenter &r);
};

#endif