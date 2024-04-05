class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        
        int i = 0, j = 0;
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < nums1.size()){
            merged.push_back(nums1[i]);
            i++;
        }
        
        while(j < nums2.size()){
            merged.push_back(nums2[j]);
            j++;
        }
        
        double ans = 0;
        int n = merged.size();
        
        if(n % 2 != 0){
            ans = merged[(n/2)];
        }
        else{
            int left = merged[(n/2)-1];
            int right = merged[(n/2)];
            ans = (left + right) / 2.0;
        }
        
        return ans;
    }
};