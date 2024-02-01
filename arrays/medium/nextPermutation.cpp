vector<int> nextGreaterPermutation(vector<int> &arr) {
    int n=arr.size();
    int index=-1;// index stored the threshold/breakpoint

    // this will give longer prefix match
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }

    // edge case: instead of no break point,this will be the last permutation 
    // next permutation would be the first one,so it would be reversed
    // sort the remaining array ( by reversing them )
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }    

    // find smallest value > threshold value,and swap
    for(int i=n-1;i>index;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

    //sort the remaining array -> reverse them
    reverse(arr.begin()+index+1,arr.end());

    return arr;
}
 