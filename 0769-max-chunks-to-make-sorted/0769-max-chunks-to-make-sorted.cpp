class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        vector<int>maxArray;
        int n = arr.size();
        
        int x = arr[0];
        maxArray.push_back(x);
        
        for(int i = 1; i<n; i++){
            int x = max(maxArray[i-1], arr[i]);
            maxArray.push_back(x);
        }
        
        int count = 0;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i<n; i++){
            if(arr[i] == maxArray[i]) count++;
        }
        
        return count;
    }
};