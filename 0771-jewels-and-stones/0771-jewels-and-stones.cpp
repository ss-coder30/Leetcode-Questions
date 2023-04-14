class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int j_n = jewels.length();
        int s_n = stones.length();
        
        int count = 0;
        
        for(int i=0; i<s_n; i++){
            for(int j=0; j<j_n; j++){
                if(stones[i]==jewels[j]){
                    count++;
                }
            }
        }
        return count;
    }
};