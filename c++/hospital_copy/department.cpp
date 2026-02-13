#include <iostream>
using namespace std;
#include "department.h"
#include <string.h>

department::department(const string &dep_name)
{
   this->dep_name = dep_name;
}
bool department::set_dep_name(string &dep_name)
{
   this->dep_name = dep_name;
   return true;
}
const string &department::get_dep_name() const
{
   return dep_name;
}

const list<doctor *> &department::get_doctor_arr() const //
{
   return doctor_arr;
}
const list<nurse> &department::get_nurse_arr() const //
{
   return this->nurse_arr;
}

bool department::add_doctor_to_dep(doctor *doctorPtr)
{

   doctor_arr.push_back(doctorPtr);
   (*doctorPtr).set_departmentPtr(this);
   return true;
}

bool department::add_nurse_to_dep(nurse *nursePtr)
{

   nurse_arr.push_back(*nursePtr);
   nurse_arr.back().set_departmentPtr(this);
   // (*nursePtr).set_departmentPtr(this);
   return true;
}

ostream &operator<<(ostream &os, const department &dep)
{
   os << "Department Details \n";
   os << "name: " << dep.dep_name << "\n";

   list<doctor *>::const_iterator itr = dep.doctor_arr.begin();
   list<doctor *>::const_iterator itrEnd = dep.doctor_arr.end();

   for (; itr != itrEnd; ++itr)
   {
      if (typeid(**itr) == typeid(surgeon))
      {
         os << *(surgeon *)(*itr);
      }
      else
      {
         os << **itr << endl;
      }
   }
   list<nurse>::const_iterator itr2 = dep.nurse_arr.begin();
   list<nurse>::const_iterator itrEnd2 = dep.nurse_arr.end();
   if (itr2 == itrEnd2)
   {
      return os;
   }
   for (; itr2 != itrEnd2; ++itr2)
   {
      os << *itr2 << endl;
   }
   return os;
}
