class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i = 0, j = n-1;
        int capacity = 0;
        
        while(i<j){
            capacity = max(capacity, (j-i)*min(height[i], height[j]));
            
            (height[i] < height[j]) ? i++ : j--;
        }
        
        return capacity;
            
    }
};