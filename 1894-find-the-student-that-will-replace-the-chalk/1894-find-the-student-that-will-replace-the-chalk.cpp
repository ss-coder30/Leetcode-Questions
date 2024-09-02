class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the total chalk usage in one round
        long long totalChalk = 0;
        for(int c : chalk) {
            totalChalk += c;
        }
        
        // Reduce k to avoid unnecessary rounds
        k %= totalChalk;
        
        // Find the student who will replace the chalk
        for(int i = 0; i < chalk.size(); i++) {
            if(k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // The code should never reach here because the problem guarantees a solution
        return -1;
    }
};
