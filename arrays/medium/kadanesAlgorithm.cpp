#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std; 


// brute force: print all subarrays and calculate sum for each
vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
int n=arr.size();
int maxSub=INT_MIN;
int sum=0;
  for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum=0;
            cout << "[ ";
            for (int k = i; k <= j; k++)
            {
                sum=sum+arr[k];
                cout << arr[k] << " ";
            }
            cout << "]" << sum<< endl;
            maxSub=max(maxSub,sum);
            
        }
    }
    cout<<endl<<"Max Sum : "<<maxSub;


  // better solution: adding sum of previous subarray with next element
  int maxSub=INT_MIN;
  int sum=0;
  for (int i = 0; i < n; i++)
    {
         sum=0;
        for (int j = i; j < n; j++)
        {
            sum=sum+arr[j];
            cout<<arr[i]<<" "<<arr[j]<<" "<<sum<<endl;
            maxSub=max(maxSub,sum);
            
        }
       
    }
    cout<<endl<<"Max Sum : "<<maxSub;

// optimal solution: kadane's algorithm,if sum<0,drop/neglect it,until then add sum ,and check if it's maximum
 
  int maxSub=INT_MIN;
  int sum=0;

  // to print subarray
  int ansStart=-1;
  int ansEnd=-1;
  int start=0;
  for (int i = 0; i < n; i++)
    {
        // this will indicate the starting point for subarray
        if(sum==0){
            start=i;
        }
        sum=sum+arr[i];
        if(sum>maxSub){
            maxSub=sum;
            ansStart=start;
            ansEnd=i; // i is the current end index
        }

      // neglecting the negative sum  
      if(sum<0){
          sum=0;
      }
       
    }
    cout<<endl<<"Max Sum : "<<maxSub<<endl;
    cout<<"Starting element : "<<arr[ansStart]<<endl;
    cout<<"Ending element : "<<arr[ansEnd]<<endl;
    cout<<"Subarray : ";
    for(int i=ansStart;i<=ansEnd;i++){
         cout<<arr[i]<<" ";
    }