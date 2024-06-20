class Solution {
public:
    bool isValid(vector<int>& position, int mid, int m) {
        int initial = 1, prev = position[0];
        
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - prev >= mid) {
                initial++;
                prev = position[i];
                if(initial == m) return true;
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        int ans = 0;
        
        sort(position.begin(), position.end());
        
        int low = 1, high = position[n-1] - position[0];
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(position, mid, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};