
// Brute Force: using 2 loops
// The idea is pretty simple here, We will start with the element at the 0th index, and will compare it with all of its future elements that are present in the array.
// If the picked element is smaller than or equal to all of its future values then we will move to the next Index/element until the whole array is traversed.
// If any of the picked elements is greater than its future elements, Then simply we will return False.
// If the size of the array is Zero or One i.e ( N = 0 or N = 1 ) or the entire array is traversed successfully then we will simply return True.
int isSorted(int n, vector<int> arr)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[i])
      {
        return 0;
        break;
      }
    }
  }

  return 1;
}

// Optimal: using single/linear traversal,loop starts from 1st index instead of 0th
// As we know that for a sorted array the previous of every element is smaller than or equal to its current element.
// So, Through this, we can conclude that if the previous element is smaller than or equal to the current element then. Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted.
// We will check every element with its previous element if the previous element is smaller than or equal to the current element then we will move to the next index.
// If the whole array is traversed successfully or the size of the given array is zero or one (i.e N = 0 or N = 1). Then we will return True else return False.
int isSorted(int n, vector<int> arr)
{
  for (int i = 1; i < n; i++)
  {
    if (arr[i - 1] > arr[i])
    {
      return 0;
      break;
    }
  }
  return 1;
}