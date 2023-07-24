#include<bits/stdc++.h>
using namespace std;

/*

What is Lower Bound?

The lower bound algorithm finds the first or the smallest index in a sorted array
 where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such 
index is not found, the lower bound algorithm returns n i.e. size of the given array.

*/

int lowerBound(vector<int>& nums, int target)
{
    int n = nums.size();
    int low = 0, high = n-1, ans = n;
    while(low<=high)
    {
        int mid = low + ((high - low)/2);
        if(nums[mid]>=target)
        {
            high = mid - 1;
            ans = mid;
        }
        else low = mid + 1;
    }
    return ans;
}

/*

What is Upper Bound?
The upper bound algorithm finds the first or the smallest index in a sorted array 
where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

But if any such index is not found, the upper bound algorithm returns n i.e. size 
of the given array. 

*/

int upperBound(vector<int>& nums, int target)
{
    int n = nums.size();
    int low = 0, high = n-1, ans = n;
    while(low<=high)
    {
        int mid = low + ((high - low)/2);
        if(nums[mid]>target)
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
/*

The main difference between the lower and upper bound is in the condition.
For the lower bound the condition was arr[ind] >= x and here, in the case 
of the upper bound, it is arr[ind] > x.

*/

// The algorithm works for sorted arrays.