#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Student
{
public:
    int rollno;
    string name;
    int age;
};

class Teacher
{
public:
    string subject;
    double salary;
};
class TA : public Student, public Teacher
{
};
int main()
{
    TA s1;
    s1.name = "akshay";
    s1.subject = "ML";
    cout << s1.name << endl;
    cout << s1.subject << endl;

    return 0;
}