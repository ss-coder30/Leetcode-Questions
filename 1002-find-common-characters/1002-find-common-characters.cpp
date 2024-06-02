class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        // Initialize two hash vectors to store character frequencies
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        // Initialize the first hash vector with character frequencies from the first word
        for (int i = 0; i < words[0].size(); i++)
            hash1[words[0][i] - 'a']++;

        // Iterate through the remaining words to update the hash vectors
        for (int i = 1; i < words.size(); i++) {
            // Update hash2 with character frequencies from the current word
            for (auto ch : words[i])
                hash2[ch - 'a']++;

            // Update hash1 by taking the minimum of corresponding frequencies in hash1 and hash2
            for (int i = 0; i < 26; i++) {
                hash1[i] = std::min(hash1[i], hash2[i]);
                hash2[i] = 0;  // Reset hash2 for the next iteration
            }
        }

        // Create a result vector based on the final hash1 vector
        vector<std::string> ans;
        for (int i = 0; i < 26; i++) {
            if (hash1[i] > 0) {
                int count = hash1[i];
                while (count--) {
                    char x = i + 'a';
                    std::string s;
                    s = x;
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};