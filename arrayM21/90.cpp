// https://leetcode.com/problems/subsets-ii/
// 90. Subsets II
// approach:
// any element has tow options, we can include it or not.
// if we decide an element to include then we can go and decide about the next element.
// but if we decide to igonre a element, then we have to ignore all such elements.


class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void recurse(vector<int>& nums, int index){
        if(index == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        recurse(nums,index+1);
        temp.pop_back();
        int i=index,n=nums.size();
        while(i<n-1 && nums[i]==nums[i+1]){
            i++;
        }
        recurse(nums,i+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recurse(nums, 0);
        return result;
    }
};