#include <iostream>
using namespace std;

// swap numbers using xor
void swapNumbers(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    int a = 5;
    int b = 6;
    cout << "Before swapping: a=" << a << " b=" << b << endl;
    swapNumbers(a, b);
    cout << "After swapping: a=" << a << " b=" << b << endl;
    return 0;
}
