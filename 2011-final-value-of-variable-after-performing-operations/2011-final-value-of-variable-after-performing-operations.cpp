#include<bits/stdc++.h>

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int X =0 ;
        for(int i=0; i<n; i++){
            if(operations[i]=="--X" || operations[i]=="X--"){
                X = X-1;
            }
            else{
                X = X+1;
            }
        }
        return X;
    }
};