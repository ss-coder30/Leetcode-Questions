class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // better solution
        // time complexity - O(n^3)
        // space complexity - O(1)
        
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                
                set<long long> hashSet;
                for(int k = j+1; k<n; k++){
                    
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    
                    long long fourth = target - sum;
                    
                    // if fourth element is present in hashSet
                    if(hashSet.find(fourth) != hashSet.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        // to make the vector unique
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    
                    // adding the element to the hashSet
                    hashSet.insert(nums[k]);
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
};