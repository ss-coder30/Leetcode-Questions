class Solution {
public:
    
    bool checkPalindrome(string s, int start, int end){
        
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        
        return true;
    }
    
    void palindromePart(int index, string s, vector<string> &ds, vector<vector<string>> &ans){
        
        // base case
        if(index == s.size()){
            ans.push_back(ds);
            return;
        }
        
        // looping through all indexes
        for(int i = index; i<s.size(); i++){
            if(checkPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                
                palindromePart(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector <string>>ans;
        vector <string> ds;
        
        palindromePart(0, s, ds, ans);
        return ans;
    }
};