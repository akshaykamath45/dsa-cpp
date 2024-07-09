// brute force - iterate through the array using 2 for loops starting from 0, maintain count of each element

// better - using hash map, store freq of each element

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> hash;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }
    for (auto i : hash)
    {
        if (i.second > n / 2)
        {
            return i.first;
        }
    }
    return -1;
}

int majorityElement(vector<int> &nums)
{
    // optimal - moores voting algorithm
    // maintain a counter with initial value = 0 , and a element
    // if count == 0 , update element with arr[i] , and make count=1
    // if the current element arr[i] = element, count++
    // else count --
    // at last we will get the element with count> 0, although this count
    // has no significance, we get the element we can reverify by running
    // again a for loop to check if the element occurs > n/2
    int n = nums.size();
    int element;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count = 1;
        }
        else if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // verifying again if the element's count > n/2 if majority element not present in array
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element)
        {
            count1++;
        }
    }
    if (count1++ > (n / 2))
    {
        return element;
    }
    return -1;
}