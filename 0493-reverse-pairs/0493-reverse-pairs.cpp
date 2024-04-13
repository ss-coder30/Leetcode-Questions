class Solution {
public:
    
    void merge(int low, int mid, int high, vector<int> &nums, int &ans){
        vector<int> temp1, temp2;
        
        for(int i = low; i<=mid; i++){
            temp1.push_back(nums[i]);
        }
        
        for(int i = mid+1; i<=high; i++){
            temp2.push_back(nums[i]);
        }
        
        for(int i = 0; i<temp2.size(); i++){
            long long d = temp2[i];
            auto it = upper_bound(temp1.begin(), temp1.end(), 2*d);
            int x = temp1.end()-it;
            ans += x;
        }
        
        int i = 0, j = 0;
        while(i < temp1.size() && j < temp2.size()){
            if(temp1[i] <= temp2[j]){
                nums[low] = temp1[i];
                i++;
                low++;
            }
            else {
                nums[low] = temp2[j];
                j++;
                low++;
            }
        }
        
        while(i < temp1.size()){
            nums[low] = temp1[i];
            i++;
            low++;
        }
        
        while(j < temp2.size()){
            nums[low] = temp2[j];
            j++;
            low++;
        }
    }
    
    void mergeSort(int low, int high, vector<int> &nums, int &ans){
        if(low >= high) return;
        
        int mid = (low + high)/2;
        mergeSort(low, mid, nums, ans);
        mergeSort(mid+1, high, nums, ans);
        merge(low, mid, high, nums, ans);
    }
    
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(0, nums.size()-1, nums, ans);
        
        return ans;
    }
};