class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        int n = target.size();
        unordered_map<int, int> targetFreq, arrFreq;
        
        for(int i = 0; i<n; i++){
            targetFreq[target[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            arrFreq[arr[i]]++;
        }
        
        return targetFreq == arrFreq;
    }
};