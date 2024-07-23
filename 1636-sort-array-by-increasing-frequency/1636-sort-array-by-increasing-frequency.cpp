class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<pair<int, int>> freq;
        unordered_map<int, int> hash;
        vector<int> ans;
        
        for(const auto& it: nums){
            hash[it]++;
        }
        
        for(const auto& it: hash){
            pair p = {it.first, it.second};
            freq.push_back(p);
        }
        
        sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            
            return a.second < b.second;
        });
        
        for(int i = 0; i<freq.size(); i++){
            while(freq[i].second > 0){
                int x = freq[i].first;
                ans.push_back(x);
                freq[i].second--;
            }
        }
        
        return ans;
    }
};