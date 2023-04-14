class Solution {
public:
    string defangIPaddr(string address) {
        string def_add;
        int n = address.length();
        
        for(int i=0; i<n; i++){
            if(address[i]== '.'){
                def_add += "[.]";
            }
            else{
                def_add += address[i];
            }
        }
        return def_add;
    }
};