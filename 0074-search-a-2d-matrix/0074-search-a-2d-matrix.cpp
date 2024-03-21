class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0, high = m*n-1;
        
        while(high - low >= 0){
            int mid = (high + low)/2;
            
            int pivot = matrix[mid/m][mid%m];
            
            if(pivot == target) return true;
            else if(pivot > target) high = mid-1;
            else low = mid+1;
        }
        
        return false;
    }
};