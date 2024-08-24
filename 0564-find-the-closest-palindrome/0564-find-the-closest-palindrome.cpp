class Solution {
public:
    long long int evenPalindrome(long long int val) {
        long long int temp = val;
        while (temp != 0) {
            val = val * 10 + temp % 10;
            temp /= 10;
        }
        return val;
    }

    long long int oddPalindrome(long long int val, long long int temp) {
        while (temp != 0) {
            val = val * 10 + temp % 10;
            temp /= 10;
        }
        return val;
    }

    void updateMinDiff(long long int org, long long int& val, long long& minDiff,
                 long long int& ans) {
        if (abs(org - val) < minDiff && abs(org - val) != 0) {
            ans = val;
            minDiff = abs(org - val);
        } else if (abs(org - val) == minDiff)
            ans = min(ans, val);
    }
    
    string nearestPalindromic(string s) {
        long long int n = s.size();
        long long int original = stoll(s);

        long long int oddHalf = 0, evenHalf = 0;
        for (int i = 0; i <= n / 2; i++) {
            oddHalf = oddHalf * 10 + s[i] - '0';
            if (i < n / 2) evenHalf = evenHalf * 10 + s[i] - '0';
        }
        long long int minDiff = LLONG_MAX;
        long long int ans = LLONG_MAX;
        
        long long int first = n % 2 == 0 ? evenPalindrome(evenHalf) : oddPalindrome(oddHalf, oddHalf / 10);
        updateMinDiff(original, first, minDiff, ans);
        long long int second = n % 2 == 0 ? evenPalindrome(evenHalf - 1) : oddPalindrome(oddHalf - 1, (oddHalf - 1) / 10);
        updateMinDiff(original, second, minDiff, ans);
        long long int third = n % 2 == 0 ? evenPalindrome(evenHalf + 1) : oddPalindrome(oddHalf + 1, (oddHalf + 1) / 10);
        updateMinDiff(original, third, minDiff, ans);

        long long int fourth = pow(10, n - 1) - 1;
        updateMinDiff(original, fourth, minDiff, ans);

        long long int fifth = pow(10, n) + 1;
        updateMinDiff(original, fifth, minDiff, ans);

        return to_string(ans);
    }
};
