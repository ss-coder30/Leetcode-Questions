class Solution {
public:
    int passThePillow(int n, int time) {
        int curr = 1;
        bool forward = true; // True means moving from 1 to n, false means moving from n to 1

        while (time > 0) {
            if (forward) {
                if (curr < n) {
                    curr++;
                } else {
                    curr--;
                    forward = false;
                }
            } else {
                if (curr > 1) {
                    curr--;
                } else {
                    curr++;
                    forward = true;
                }
            }
            time--;
        }
        
        return curr;
    }
};
