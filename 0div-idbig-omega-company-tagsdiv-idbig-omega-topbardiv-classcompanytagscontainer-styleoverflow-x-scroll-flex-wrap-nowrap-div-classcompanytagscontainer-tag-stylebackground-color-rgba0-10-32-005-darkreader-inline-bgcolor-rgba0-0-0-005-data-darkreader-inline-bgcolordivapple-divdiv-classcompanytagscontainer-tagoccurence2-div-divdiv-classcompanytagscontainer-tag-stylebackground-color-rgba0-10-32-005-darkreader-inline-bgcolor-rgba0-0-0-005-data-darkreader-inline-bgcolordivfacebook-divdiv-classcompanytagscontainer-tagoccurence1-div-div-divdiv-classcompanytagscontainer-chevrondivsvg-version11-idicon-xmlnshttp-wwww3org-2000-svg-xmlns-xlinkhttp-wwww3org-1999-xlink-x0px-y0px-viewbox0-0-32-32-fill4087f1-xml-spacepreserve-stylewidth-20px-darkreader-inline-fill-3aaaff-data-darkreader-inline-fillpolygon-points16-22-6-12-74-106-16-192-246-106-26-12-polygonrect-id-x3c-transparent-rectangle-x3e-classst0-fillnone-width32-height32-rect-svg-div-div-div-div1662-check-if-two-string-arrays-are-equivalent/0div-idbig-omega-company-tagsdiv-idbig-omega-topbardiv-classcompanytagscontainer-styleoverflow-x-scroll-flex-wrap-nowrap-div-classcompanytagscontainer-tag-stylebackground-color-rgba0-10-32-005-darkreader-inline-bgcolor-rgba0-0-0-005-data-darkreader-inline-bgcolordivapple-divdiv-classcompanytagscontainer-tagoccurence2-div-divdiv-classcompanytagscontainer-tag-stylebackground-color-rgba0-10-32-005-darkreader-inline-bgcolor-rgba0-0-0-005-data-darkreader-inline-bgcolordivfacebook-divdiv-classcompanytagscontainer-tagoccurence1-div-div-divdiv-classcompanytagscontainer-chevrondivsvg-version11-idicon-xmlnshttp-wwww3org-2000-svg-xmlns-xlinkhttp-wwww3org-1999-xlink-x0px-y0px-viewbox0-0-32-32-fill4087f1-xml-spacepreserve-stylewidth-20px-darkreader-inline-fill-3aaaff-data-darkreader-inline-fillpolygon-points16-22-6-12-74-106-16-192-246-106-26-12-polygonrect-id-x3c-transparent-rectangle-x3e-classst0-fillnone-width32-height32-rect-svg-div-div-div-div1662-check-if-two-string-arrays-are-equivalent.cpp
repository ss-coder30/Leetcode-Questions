class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string finalWord1, finalWord2;
        
        int n1 = word1.size();
        int n2 = word2.size();
        
        for(int i = 0; i<n1; i++){
            finalWord1 += word1[i];
        }
        
        for(int i = 0; i<n2; i++){
            finalWord2 += word2[i];
        }
        
        if(finalWord1 == finalWord2){
            return true;
        }
        else{
            return false;
        }
    }
};