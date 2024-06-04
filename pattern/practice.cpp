#include <iostream>
using namespace std;

// basic pattern
void printPattern1(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// printing diagonals
// y=mx+c
// matching condition i=j
void printPattern2(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// matching condition , i+j==c // c=constant, here c=4
void printPattern3(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// used to print a cross, checks 2 conditions
void printPattern4(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + j == n - 1 || i == j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
// print right triangle
void printPattern5(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + j >= n - 1)
            { // main condition just make this >=
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// print left triangle
void printPattern6(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i >= j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// important printing pyramid
void printPattern7(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2 * n - 1; j++)
        {
            if (i + j >= n - 1 && i >= j - n + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    printPattern1(5, 5);
    printPattern2(5, 5);
    printPattern3(5, 5);
    printPattern4(5, 5);
    printPattern5(5, 5);
    printPattern6(5, 5);
    printPattern7(5, 5);
    return 0;
}
