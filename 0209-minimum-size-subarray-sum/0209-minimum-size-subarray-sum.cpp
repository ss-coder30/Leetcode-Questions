class Solution {
public:
    
    bool func(int mid,int k, vector<int> nums){
    int sum=0;
    for(int i=0;i<mid;i++){
        sum+=nums[i];
        if(sum>=k) return true;
        
    }
    int j=0;
    for(int i=mid;i<nums.size();i++){
        sum+=nums[i];
        sum-=nums[j];
        j++;
        if(sum>=k){
            return true;
        }
    }
    return false;

}
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=1,high=nums.size();
        while(high-low>1){
            int mid=(low+high)/2;
            if(func(mid,target,nums)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        if(func(low,target,nums)) return low;
        else if(func(high,target,nums)) return high;
        else return 0;
    }
};