class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        
        while(n != 1){
            if(st.find(n) != st.end()){
                return false;
            }
            else{
                st.insert(n);
            }
            
            int temp = 0;
            while(n > 0){
                temp = temp + ((n%10) * (n%10));
                n /= 10;
            }
            n = temp;
        }
        return true;
    }
};