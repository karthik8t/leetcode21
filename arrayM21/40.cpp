// https://leetcode.com/problems/combination-sum-ii/
// 40. Combination Sum II

// Approach:
// every element will have two options, either it will present in one of the 
// list or not.
// using backtracking we can ignore an element or consider it, we have to explore
// the list with both the options

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void recurse(vector<int>& candidates, int target, int index){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            recurse(candidates,target-candidates[i],i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        recurse(candidates,target,0);
        return result;
    }
};