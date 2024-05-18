class Solution {
public:
    
    void permutations(vector<int>& visited, vector<int>& temp, vector<int>& nums, set<vector<int>>& st, int n){
        
        //base case
        if(temp.size() == n){
            st.insert(temp);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(visited[i] == 1){
                continue;
            }
            
            temp.push_back(nums[i]);
            visited[i] = 1;
            permutations(visited, temp, nums, st, n);
            visited[i] = 0;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> st;
        vector<int> temp;
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<vector<int>> ans;
        
        permutations(visited, temp, nums, st, n);
        
        for(auto it: st){
            ans.push_back(it);
        }
        
        return ans;
    }
};