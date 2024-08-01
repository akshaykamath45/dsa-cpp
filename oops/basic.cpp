#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Teacher
{
    // properties/attributes
public:
    string name;
    string department;
    string subject;
    double salary;

    // methods/member functions
    void updateSalary(double newSalary)
    {
        salary = newSalary;
    }
};

int main()
{
    Teacher t1;
    t1.name = "akshay";
    t1.department = "comps";
    t1.updateSalary(20000);
    cout << t1.name << " " << t1.salary;
    return 0;
}