class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        std::unordered_map<string, vector<string>> hash_table;

        // Time: O(n * m)
        // Space: O(n * m)
        for (auto& str : strs)
        {
            string signature;
            vector<int> signature_array(26, 0);

            // Count each letter in string.
            for (auto& letter : str)
            {
                int letter_i = letter - 'a';
                signature_array[letter_i]++;
            }

            // Create signature from letter count of string.
            for (auto& letter_count : signature_array)
            {
                signature.push_back(letter_count + '0');
            }

            // If signature already exists, add string to group.
            if (hash_table.contains(signature))
            {
                hash_table[signature].emplace_back(str);
            }
            // Otherwise, create new group with string.
            else
            {
                vector<string> group;
                group.emplace_back(str);
                hash_table.emplace(signature, group);
            }
        }

        // Time: O(n)
        // Space: O(n)
        for (auto& [signature, group] : hash_table)
        {
            groups.emplace_back(group);
        }

        return groups;
    }
};