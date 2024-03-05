class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int maxCount = 0;
        
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                int start = nums[i], count = 0;
                do{
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }
                while(start != nums[i]);
                
                maxCount = max(count, maxCount);
            }
        }
        
        return maxCount;
    }
};