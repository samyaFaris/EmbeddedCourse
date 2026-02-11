#include <iostream>
using namespace std;
#include "hospital.h"
#include "person.h"
#include <string.h>

int main()
{
    hospital hospitalA("Hospital A", "reaserchCenterA");
    hospitalA.add_department_to_hospital("Kids");
    hospitalA.add_doctor_to_hospital("Samya", "234876591", "KidsEXP", "Kids");
    hospitalA.add_nurse_to_hospital("Kanar", "234876591", 3, "Kids");
    hospitalA.add_researcher_to_hospital("Sarah", "234876591");
    hospitalA.add_article("1/1/2026", "Sport", "N12", "234876591");
    hospitalA.add_patient_to_hospital("123456789", "Samya Faris", 1998, "Female");
    hospitalA.add_patient_to_hospital("207570843", "Bsel Faris", 1998, "Female");
    hospitalA.add_visit("12/12/26", "123456789");
    hospitalA.add_visit("13/07/26", "123456789");
    hospitalA.add_visit("25/08/26", "207570843");

    cout << hospitalA;
    return 0;
}