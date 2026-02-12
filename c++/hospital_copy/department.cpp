#include <iostream>
using namespace std;
#include "department.h"
#include <string.h>

department::department(const string &dep_name) : Physical_size(2), logical_size(0), nurse_logical_size(0), nurse_Physical_size(2)
{
   this->dep_name = dep_name;
   doctor_arr = new doctor *[Physical_size];
   for (int i = 0; i < Physical_size; i++)
   {
      doctor_arr[i] = nullptr;
   }
   nurse_arr = new nurse *[nurse_Physical_size];
   for (int i = 0; i < nurse_Physical_size; i++)
   {
      nurse_arr[i] = nullptr;
   }
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

doctor **department::get_doctor_arr() const
{
   return doctor_arr;
}
nurse **department::get_nurse_arr() const
{
   return this->nurse_arr;
}

department::~department()
{
   delete[] doctor_arr;
   delete[] nurse_arr;
}
bool department::add_doctor_to_dep(doctor *doctorPtr)
{
   if (logical_size < Physical_size)
   {

      this->doctor_arr[logical_size] = doctorPtr;
      (*doctorPtr).set_departmentPtr(this);
      logical_size++;
   }
   else if (logical_size == Physical_size)
   {
      Physical_size *= 2;
      doctor **temp = new doctor *[Physical_size];
      for (int i = 0; i < logical_size; i++)
      {
         temp[i] = doctor_arr[i];
      }
      delete[] doctor_arr;
      this->doctor_arr = temp;
      doctor_arr[logical_size] = doctorPtr;
      (*doctorPtr).set_departmentPtr(this);
      logical_size++;
   }
   return true;
}

bool department::add_nurse_to_dep(nurse *nursePtr)
{
   if (nurse_logical_size < nurse_Physical_size)
   {

      this->nurse_arr[nurse_logical_size] = nursePtr;
      (*nursePtr).set_departmentPtr(this);
      nurse_logical_size++;
   }
   else if (nurse_logical_size == nurse_Physical_size)
   {
      nurse_Physical_size *= 2;
      nurse **temp = new nurse *[nurse_Physical_size];
      for (int i = 0; i < nurse_logical_size; i++)
      {
         temp[i] = nurse_arr[i];
      }
      delete[] nurse_arr;
      this->nurse_arr = temp;
      nurse_arr[nurse_logical_size] = nursePtr;
      (*nursePtr).set_departmentPtr(this);
      nurse_logical_size++;
   }
   return true;
}

ostream &operator<<(ostream &os, const department &d)
{
   os << "Department Details \n";
   os << "name: " << d.dep_name << "\n";
   os << "Logical Size: " << d.logical_size << "\n";
   os << "Physical Size: " << d.Physical_size << "\n";
   for (int i = 0; i < d.logical_size; i++)
   {
      if (d.doctor_arr[i] != nullptr)
      {
         cout << (*d.doctor_arr[i]);
      }
   }
   for (int i = 0; i < d.nurse_logical_size; i++)
   {
      if (d.nurse_arr[i] != nullptr)
      {
         os << (*d.nurse_arr[i]);
      }
   }
   return os;
}
