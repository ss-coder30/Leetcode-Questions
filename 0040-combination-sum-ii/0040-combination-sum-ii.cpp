class Solution {
    
private:
    void findCombinations(int n, int index, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& a){
        
        // base case
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i<n; i++){
            
            // base case
            // consecutive duplicates
            if(i > index && a[i] == a[i-1]) continue;
            
            // if a[i] > target
            if(a[i] > target) break;
            
            //pick
            ds.push_back(a[i]);
            findCombinations(n, i+1, target-a[i], ds, ans, a);
            
            //backtrack
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        
        sort(candidates.begin(), candidates.end());
        
        findCombinations(n, 0, target, ds, ans, candidates);
        
        return ans;
    }
};