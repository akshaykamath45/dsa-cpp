// brute force: combine both arrays and return median based on even or odd number of elements
// takes extra space complexity O(n) to store the combination of arrays
double median(vector<int> &a, vector<int> &b)
{
    vector<int> a3;
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            a3.push_back(a[i]);
            i++;
        }
        else
        {
            a3.push_back(b[j]);
            j++;
        }
    }
    while (i < n1)
    {
        a3.push_back(a[i]);
        i++;
    }
    while (j < n2)
    {
        a3.push_back(b[j]);
        j++;
    }
    if (n % 2 == 0)
    {
        return (double)((double)a3[n / 2] + (double)a3[n / 2 - 1]) / 2.0;
    }
    else
    {
        return a3[n / 2];
    }
    return -1;
}

// better: reducing the space complexity,without using the third array,maintaining the count
double median(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    int indEle2 = n / 2;
    int indEle1 = indEle2 - 1;

    int count = 0;
    int ele1 = -1, ele2 = -1;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (count == indEle1)
            {
                ele1 = a[i];
            }
            if (count == indEle2)
            {
                ele2 = a[i];
            }
            count++;
            i++;
        }
        else
        {
            if (count == indEle1)
            {
                ele1 = b[j];
            }
            if (count == indEle2)
            {
                ele2 = b[j];
            }
            count++;
            j++;
        }
    }
    while (i < n1)
    {
        if (count == indEle1)
        {
            ele1 = a[i];
        }
        if (count == indEle2)
        {
            ele2 = a[i];
        }
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == indEle1)
        {
            ele1 = b[j];
        }
        if (count == indEle2)
        {
            ele2 = b[j];
        }
        count++;
        j++;
    }
    if (n % 2 == 0)
    {
        return (double)(double)(ele1 + ele2) / 2.0;
    }
    else
    {
        return ele2;
    }
    return -1;
}

// using binary search: we will pick number of elements to picked from arr1 by maintaining 4 pointers l1 l2 r1 and r2

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2)
    {
        return median(
            b, a); // want arr1 to be smallest,that should contain least elements
    }
    int low = 0;
    int high = n1; // min(n1,n2)
    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;
    while (low <= high)
    {

        int mid1 = (low + high) >> 1; // low+high/2
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        // if the index doesn't exists
        if (mid1 < n1)
        {
            r1 = a[mid1];
        }
        if (mid2 < n2)
        {
            r2 = b[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = a[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = b[mid2 - 1];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}