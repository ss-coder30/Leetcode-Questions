class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        map<int, int> m;
        vector<int> ans(n);
        
        // storing and mapping starting values of intervals with index
        for(int i = 0; i<n; i++){
            m[intervals[i][0]] = i;
        }
        
        for(int i = 0; i<n; i++){
            ans[i] = m.lower_bound(intervals[i][1]) != m.end() ? m.lower_bound(intervals[i][1]) -> second : -1;
        }
        
        return ans;
    }
};