class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector shuffled_nums(2*n,0);
int a=0,b=n;
int c=0,d=1;
for(int i=0;i<n;i++)
{
shuffled_nums[c]=nums[a];
shuffled_nums[d]=nums[b];
a++;
b++;
c = c+2;
d = d+2;
}
return shuffled_nums;
    }
};