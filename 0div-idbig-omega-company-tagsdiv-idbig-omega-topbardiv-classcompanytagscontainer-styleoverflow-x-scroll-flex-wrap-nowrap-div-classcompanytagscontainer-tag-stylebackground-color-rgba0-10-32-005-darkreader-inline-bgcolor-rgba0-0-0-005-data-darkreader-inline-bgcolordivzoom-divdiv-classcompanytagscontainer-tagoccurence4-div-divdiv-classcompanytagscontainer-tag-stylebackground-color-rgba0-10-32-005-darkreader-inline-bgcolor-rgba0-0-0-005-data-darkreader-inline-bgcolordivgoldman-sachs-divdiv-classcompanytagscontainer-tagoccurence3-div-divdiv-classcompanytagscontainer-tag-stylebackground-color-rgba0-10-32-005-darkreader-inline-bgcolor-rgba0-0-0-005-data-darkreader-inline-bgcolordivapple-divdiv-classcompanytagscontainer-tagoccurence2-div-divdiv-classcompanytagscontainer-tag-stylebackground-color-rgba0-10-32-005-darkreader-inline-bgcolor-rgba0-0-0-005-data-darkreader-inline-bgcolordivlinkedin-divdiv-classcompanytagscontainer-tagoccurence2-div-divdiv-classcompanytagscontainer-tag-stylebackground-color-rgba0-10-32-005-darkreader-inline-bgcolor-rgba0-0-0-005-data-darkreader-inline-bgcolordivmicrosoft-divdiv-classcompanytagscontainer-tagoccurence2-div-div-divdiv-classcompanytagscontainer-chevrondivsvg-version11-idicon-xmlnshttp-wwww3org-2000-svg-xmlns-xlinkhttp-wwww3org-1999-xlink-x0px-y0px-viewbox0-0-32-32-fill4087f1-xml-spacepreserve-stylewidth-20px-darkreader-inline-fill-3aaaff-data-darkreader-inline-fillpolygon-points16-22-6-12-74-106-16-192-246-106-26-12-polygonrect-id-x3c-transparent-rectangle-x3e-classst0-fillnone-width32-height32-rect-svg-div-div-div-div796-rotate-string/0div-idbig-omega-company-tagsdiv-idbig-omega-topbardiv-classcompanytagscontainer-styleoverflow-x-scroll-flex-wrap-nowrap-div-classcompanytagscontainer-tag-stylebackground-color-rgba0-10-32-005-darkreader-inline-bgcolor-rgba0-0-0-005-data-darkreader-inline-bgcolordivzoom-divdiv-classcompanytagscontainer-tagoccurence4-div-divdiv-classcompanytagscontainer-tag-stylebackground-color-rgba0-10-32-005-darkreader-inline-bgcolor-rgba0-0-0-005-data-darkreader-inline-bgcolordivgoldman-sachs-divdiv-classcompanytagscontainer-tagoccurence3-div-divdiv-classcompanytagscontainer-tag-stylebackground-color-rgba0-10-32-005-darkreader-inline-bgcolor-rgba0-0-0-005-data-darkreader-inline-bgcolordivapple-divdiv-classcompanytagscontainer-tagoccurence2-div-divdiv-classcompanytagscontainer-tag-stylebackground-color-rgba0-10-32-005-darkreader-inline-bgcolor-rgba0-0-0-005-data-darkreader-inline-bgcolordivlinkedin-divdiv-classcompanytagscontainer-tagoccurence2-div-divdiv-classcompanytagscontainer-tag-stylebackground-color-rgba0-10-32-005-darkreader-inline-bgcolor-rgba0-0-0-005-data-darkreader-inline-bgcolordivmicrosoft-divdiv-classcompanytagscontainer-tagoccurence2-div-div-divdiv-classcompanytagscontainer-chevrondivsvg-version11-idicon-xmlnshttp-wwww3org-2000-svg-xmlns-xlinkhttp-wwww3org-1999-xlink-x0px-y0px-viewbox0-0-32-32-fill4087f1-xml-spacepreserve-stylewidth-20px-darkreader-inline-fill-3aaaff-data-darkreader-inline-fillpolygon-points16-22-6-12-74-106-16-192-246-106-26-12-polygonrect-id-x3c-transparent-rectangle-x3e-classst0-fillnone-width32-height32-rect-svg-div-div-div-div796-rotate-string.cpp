class Solution {
public:
    string leftRotate(string &s, int d){
        rotate(s.begin(), s.begin()+d, s.end());
        
        return s;
    }
    
    bool rotateString(string s, string goal) {
        
        int n = s.size();
        
        string sCopy = s;
        string goalCopy = goal;
        
        sort(sCopy.begin(), sCopy.end());
        sort(goalCopy.begin(), goalCopy.end());
        
        if(sCopy != goalCopy){
            return false;
        }
        
        for(int i = 0; i<n; i++){
            string rotatedS = leftRotate(s, 1);
            if(rotatedS == goal)
                return true;
        }
        
        return false;
    }
};