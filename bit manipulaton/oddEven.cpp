// & of last bit of odd number is always 1
string oddEven(int N)
{
    if (N & 1 != 0)
    {
        return "odd";
    }
    else
    {
        return "even";
    }
}