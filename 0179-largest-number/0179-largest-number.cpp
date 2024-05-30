class Solution {
public:
    
    // bool comp(string &a, string &b){
    //     return a+b > b+a;
    // }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> arr;
        
        for(auto it: nums){
            string s = to_string(it);
            arr.push_back(s);
        }
        
        sort(arr.begin(), arr.end(), [](string& a, string& b){return a+b > b+a; });
        
        string ans;
        
        for(auto it: arr){
            ans += it;
        }
        
        while(ans[0] == '0' && ans.length() > 1){
            ans.erase(0, 1);
        }
        
        return ans;
    }
};