#include <iostream>
using namespace std;
#include "hospital.h"
#include <string.h>

int main()
{
    hospital hospitalA("Hospital A", "reaserchCenterA");
    hospitalA.add_department_to_hospital("Kids");
    hospitalA.add_doctor_to_hospital("Samya", "KidsEXP", "Kids");
    hospitalA.add_patient_to_hospital("123456789", "Samya Faris", 1998, "Female");
    hospitalA.add_patient_to_hospital("207570843", "Bsel Faris", 1998, "Female");
    hospitalA.add_visit("12/12/26", "123456789");
    hospitalA.add_visit("13/07/26", "123456789");
    hospitalA.add_visit("25/08/26", "207570843");

    cout << hospitalA;
    return 0;
}