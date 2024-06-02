class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        vector<int> pCount(26, 0), sCount(26, 0);

        // Fill the frequency count for p and the first window of s
        for (int i = 0; i < p.size(); ++i) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        // Compare the counts of the first window
        if (pCount == sCount) ans.push_back(0);

        // Sliding window
        for (int i = p.size(); i < s.size(); ++i) {
            // Add the new character to the current window count
            sCount[s[i] - 'a']++;
            // Remove the character that is no longer in the window
            sCount[s[i - p.size()] - 'a']--;

            // Compare the counts
            if (pCount == sCount) ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};
