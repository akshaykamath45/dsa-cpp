#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Shape // abstract class
{
public:
    virtual void draw() = 0; // pure virtual function
};
class Circle : public Shape
{
public:
    void draw()
    {
        cout << "drawing circle" << endl;
    }
};
class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "drawing rectangle" << endl;
    }
};
int main()
{
    Circle c1;
    c1.draw();
    Rectangle r1;
    r1.draw();
    return 0;
}