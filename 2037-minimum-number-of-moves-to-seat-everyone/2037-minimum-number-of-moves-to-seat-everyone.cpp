class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int x = abs(seats[i] - students[i]);
            ans += x;
        }
        
        return ans;
    }
};