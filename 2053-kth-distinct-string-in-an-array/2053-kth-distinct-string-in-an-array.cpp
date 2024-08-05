class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        
        // Count the frequency of each string in arr
        for (const string& str : arr) {
            freq[str]++;
        }
        
        // Iterate through the original array to preserve order
        for (const string& str : arr) {
            if (freq[str] == 1) { // Check if the string is distinct
                k--;
                if (k == 0) { // Found the k-th distinct string
                    return str;
                }
            }
        }
        
        return ""; // If there is no k-th distinct string
    }
};
