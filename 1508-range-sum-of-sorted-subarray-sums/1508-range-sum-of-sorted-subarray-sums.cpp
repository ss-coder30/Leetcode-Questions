class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> Sum;
        
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int subSum = 0;
                for(int k = i; k<=j; k++){
                    subSum += nums[k];
                }
                Sum.emplace_back(subSum);
            }
        }
        
        sort(Sum.begin(), Sum.end());
        
        int ans = 0;
        
        for(int i = left-1; i <right; i++){
            ans = (ans + Sum[i]) % 1000000007;
        }
        return ans;
    }
};