class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;
         
        vector<int> arr(n);
        
        for(int i = 0; i<n; i++){
            arr[i] = i;
        }
        
        sort(arr.begin(), arr.end(), [&nums](int &x, int &y){
            return nums[x] == nums[y] ? x < y : nums[x] < nums[y];
        });
        
        int minIndex = n-1;
        
        for(auto i: arr){
            maxWidth = maxWidth > (i - minIndex) ? maxWidth : (i - minIndex);
            minIndex = i < minIndex ? i : minIndex;
        }
        
        return maxWidth;
        
    }
};