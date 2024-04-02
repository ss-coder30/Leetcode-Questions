class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> v(n+1); 
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            string s = words[i];
            for(int j = 0; j<s.size(); j++){
                v[i] = v[i] | (1 << (s[j] - 'a'));
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if((v[i] & v[j]) == 0){
                    int d = (words[i].size() * words[j].size());
                    ans = max(ans, d);
                }
            }
        }
        
        return ans;
    }
};