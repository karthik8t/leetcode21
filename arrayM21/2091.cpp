// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

// 2091. Removing Minimum and Maximum From Array

// intuition
// first find the lowest and highest number indices this would take O(n)
// to remove these two indices, we have to either
// 1. remove elements from only left side
// 2. remove elements from only right side
// 3. remove elements from both the sides


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int vi=0,pi=0,i,n=nums.size();
        int result = n;
        for(i=0;i<n;i++){
            if(nums[i]<nums[vi]){
                vi = i;
            }
            if(nums[i]>nums[pi]){
                pi = i;
            }
        }
        result = min(result, max(vi+1,pi+1));
        result = min(result, n-min(vi,pi));
        result = min(result, min(vi+1,pi+1)+(n-max(vi,pi)));
        return result;
    }
};