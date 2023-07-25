#include<bits/stdc++.h>
using namespace std;

int binarySearchRecursive(vector<int>&nums, int l, int h, int target)
{
    //RECURSIVE CODE   
    if(l>h)return -1;
    int m = l + ((h-l)/2);
    if(nums[m] == target)return m;
    else if(nums[m] > target)return binarySearchRecursive(nums, 0, m-1, target);
    else return binarySearchRecursive(nums, m+1, h, target);
}

int binarySearchIterative(vector<int>&nums, int l, int h, int target)
{
    //ITERATIVE CODE;
    int n = nums.size();
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = low + ((high - low)/2);
        if(nums[mid] == target)return mid;
        if(nums[mid] > target)high = mid - 1;
        else low = mid + 1;
    }
    return -1; 
}

int search(vector<int>& nums, int target) 
{ 
    int n = nums.size();
    int ansIterative = binarySearchIterative(nums, 0, n-1, target); 
    int ansRecursive = binarySearchRecursive(nums, 0, n-1, target);      
}