class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> Ans;
        int n=nums.size();
        int ans[n+n];
        for(int i=0;i<n;i++)
        {
            ans[i]=ans[n+i]=nums[i];
        }

        for(int i=0;i<(n+n);i++)
        {
            Ans.push_back(ans[i]);
        }
        return Ans;


    }
};