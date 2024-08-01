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

    // no-paramterized/ default
    Teacher()
    {
        department = "comps";
    }

    // parameterized constructor
    Teacher(string name, string department, string subject, double salary)
    {
        this->name = name;
        this->department = department;
        this->subject = subject;
        this->salary = salary;
    }

    // custom copy constructor
    Teacher(Teacher &orgObj)
    {
        cout << "from custom copy constructor" << endl;
        this->name = orgObj.name;
        this->department = orgObj.department;
        this->salary = orgObj.salary;
        this->subject = orgObj.subject;
    }

    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "department : " << department << endl;
    }
};

int main()
{
    Teacher t1;
    t1.name = "akshay";
    // t1.getInfo();
    Teacher t2("rohit", "comps", "oops", 20145);
    // t2.getInfo();
    Teacher t3(t2); 
    t3.getInfo();

    return 0;
}