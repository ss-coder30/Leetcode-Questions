class Solution {
public:
    
    void findCombinations(int index, int target, vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans){
        // base case
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < arr.size(); i++){
            if(i > index && arr[i] == arr[i-1]) continue; // skip duplicates
            if(arr[i] > target) break; // no need to proceed if the current element is greater than the remaining target
            
            ds.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i], ds, arr, ans); // move to next index for each combination
            ds.pop_back(); // backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        
        sort(candidates.begin(), candidates.end()); // sort the candidates to handle duplicates easily
        findCombinations(0, target, ds, candidates, ans);
        
        return ans;
    }
};
