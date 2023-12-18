class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        int n = words.size();
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            
            int len = words[i].size();
            
            for(int j = 0; j<len; j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
                else{
                    continue;
                }
            }
        }
        
        return ans;
        
    }
};