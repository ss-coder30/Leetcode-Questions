class Solution {   
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> peopleHeight(n);
        
        for(int i = 0; i < n; i++) {
            peopleHeight[i] = {names[i], heights[i]};
        }
        
        sort(peopleHeight.begin(), peopleHeight.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });
        
        vector<string> ans;
        for(const auto& it : peopleHeight) {
            ans.push_back(it.first);
        }
        
        return ans;
    }
};
