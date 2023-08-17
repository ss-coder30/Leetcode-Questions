class Solution {
public:
    bool isPalindrome(string s) {
        return recursiveCheck(s, 0, s.size() - 1);
    }

private:
    bool isAlphabetic(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool recursiveCheck(const string& s, int left, int right) {
        if (left >= right) {
            return true;  // Base case: empty string or single character is a palindrome
        }

        char leftChar = tolower(s[left]);
        char rightChar = tolower(s[right]);

        if (!isAlphabetic(leftChar) && !isdigit(leftChar)) {
            return recursiveCheck(s, left + 1, right);
        } else if (!isAlphabetic(rightChar) && !isdigit(rightChar)) {
            return recursiveCheck(s, left, right - 1);
        } else if (leftChar != rightChar) {
            return false;  // Characters don't match
        } else {
            return recursiveCheck(s, left + 1, right - 1);  // Recurse
        }
    }
};
