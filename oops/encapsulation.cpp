#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Teacher
{
    // properties/attributes
private:
    double salary; // data hiding

public:
    string name;
    string department;
    string subject;

    // setters
    void setSalary(double newSalary)
    {
        salary = newSalary;
    }
    // getters
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    Teacher t1;
    t1.name = "akshay";
    t1.department = "comps";
    t1.setSalary(20000);
    cout << t1.name << " " << t1.getSalary()<<endl;
    return 0;
}