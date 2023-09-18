// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
        
//         int n = nums.size();
        
//         for(int j = k; j>0; j--){
//             vector<int> temp = nums;
        
//             int first = temp[n-1];
//             nums[0] = first;
        
//             for(int i = 0; i<n-1; i++){
//                 nums[i+1] = temp[i];
//             }
//         }
        
//         return;
        
        
        
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is larger than the array size
        
        reverse(nums.begin(), nums.end()); // Reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse the first 'k' elements
        reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements
    }
};
