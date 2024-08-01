#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &obj)
    {
        this->name = obj.name;
        // deep copy
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;

        // shallow copy
        // this->cgpaPtr=obj.cgpaPtr;
    }

    void getInfo()
    {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};
int main()
{
    Student s1("rahul kumar", 8.9);
    Student s2(s1);

    // in shallow copy
    // s1.getInfo(); // 8.9
    // *(s2.cgpaPtr) = 9.2;
    // s1.getInfo(); // 9.2

    // in  deep copy
    s1.getInfo(); // 8.9
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo(); // 8.9
    s2.name = "neha";
    s2.getInfo();

    return 0;
}