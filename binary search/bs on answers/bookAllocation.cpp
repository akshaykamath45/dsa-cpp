
// using binary search
int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size();
    int pagesStudents = 0;
    int student = 1;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudents + arr[i] <= pages)
        {
            pagesStudents += arr[i];
        }
        else
        {
            student++;
            pagesStudents = arr[i];
        }
    }
    return student;
}
int findPages(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int high = sum;
    int ans = -1;
    if (m > n)
    {
        return -1;
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cntStudents = countStudents(arr, mid);
        if (cntStudents <= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}