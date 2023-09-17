class Solution {
public:
    int minimumSum(int num) {
        vector<int> a;
        int tmp = num;
        while(tmp > 0)
        {
            int rem = tmp % 10;
            a.push_back(rem);
            tmp/=10;
        }
        sort(a.begin(),a.end());
        return a[0]*10 + a[2] + a[1]*10 + a[3];
    }
};