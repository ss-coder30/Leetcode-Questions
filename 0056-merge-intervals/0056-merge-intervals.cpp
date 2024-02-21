class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0];
        int b = intervals[0][1];
        
        vector<vector<int>> ans;
        
        for(int i = 1; i<intervals.size(); i++){
            int c = intervals[i][0];
            int d = intervals[i][1];
            
            if(c <= b){
                b = max(b, d);
            }
            else{
                ans.push_back({a, b});
                a = c;
                b = d;
            }
        }
        ans.push_back({a, b});
        return ans;
    }
};