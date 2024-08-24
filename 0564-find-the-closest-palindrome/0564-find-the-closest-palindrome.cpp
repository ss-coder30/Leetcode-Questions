class Solution {
public:
    long long int reverseVal(long long int val) {
        long long int z = val;
        while (z != 0) {
            val = val * 10 + z % 10;
            z /= 10;
        }
        return val;
    }

    long long int reverseVal2(long long int val, long long int k) {
        while (k != 0) {
            val = val * 10 + k % 10;
            k /= 10;
        }
        return val;
    }

    void minDiff(long long int org, long long int& val, long long& ma,
                 long long int& ans) {
        if (abs(org - val) < ma && abs(org - val) != 0) {
            ans = val;
            ma = abs(org - val);
        } else if (abs(org - val) == ma)
            ans = min(ans, val);
    }
    string nearestPalindromic(string s) {
        long long int n = s.size();
        long long int original = stoll(s);

        long long int z = 0,k=0;
        for (int i = 0; i <=n / 2; i++) {
            z = z * 10 + s[i] - '0';
            if(i<n/2) k=k*10+s[i]-'0';
        }
        long long int ma = INT_MAX;
        long long int ans = INT_MAX;
        
        long long int first =
            n % 2 == 0 ? reverseVal(k) : reverseVal2(z, z / 10);
        minDiff(original, first, ma, ans);
        long long int second =
            n % 2 == 0 ? reverseVal(k - 1) : reverseVal2(z - 1, (z - 1) / 10);
        minDiff(original, second, ma, ans);
        long long int third =
            n % 2 == 0 ? reverseVal(k + 1) : reverseVal2(z + 1, (z + 1) / 10);
        minDiff(original, third, ma, ans);

        long long int fourth = pow(10, n - 1) - 1;
        minDiff(original, fourth, ma, ans);

        long long int fifth = pow(10, n) + 1;
        minDiff(original, fifth, ma, ans);

        return to_string(ans);
    }
};