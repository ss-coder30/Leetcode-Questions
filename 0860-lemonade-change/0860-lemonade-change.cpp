class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();
        int fiveNote = 0, tenNote = 0, twentyNote = 0;
        
        for(int i = 0; i<n; i++){
            if(bills[i] == 5){
                fiveNote++;
            }
            else if(bills[i] == 10){
                
                if(!fiveNote) return false;
                
                else {              
                    tenNote++;
                    fiveNote--;
                }
            }
            
            else {
                
                if(!fiveNote) return false;
                
                else {
                    if(tenNote) {
                        tenNote--;
                        fiveNote--;
                        twentyNote++;
                    }
                    
                    else {
                        if(fiveNote < 3) return false;
                        
                        else {
                            twentyNote++;
                            fiveNote--;
                            fiveNote--;
                            fiveNote--;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};