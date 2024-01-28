class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Store the frequency of each character
        map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Step 2: Transfer to a vector
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

        // Step 3: Sort the vector by frequency
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Descending order of frequency
        });

        string res;
        for(auto x : freqVec){
            while(x.second--){
                res += x.first;
            }
        }
        return res;
    }
};