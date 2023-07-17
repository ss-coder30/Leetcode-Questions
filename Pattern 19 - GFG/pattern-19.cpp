//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int initialSpace = 0;
        for(int i = 0; i < n; i++){
            //stars
            for(int j = 1; j<=n-i; j++){
                cout<<"*";
            }
            //spaces
            for(int j = 0; j<= initialSpace-1; j++){
                cout<<" ";
            }
            //stars
            for(int j = 1; j<=n-i; j++){
                cout<<"*";
            }
            initialSpace += 2;
            cout<<endl;
        }
        for(int i = 1; i<=n; i++){
            //stars
            for(int j = 1; j<=i; j++){
                cout<<"*";
            }
            //spaces
            for(int j = 1; j<= initialSpace-2; j++){
                cout<<" ";
            }
            //stars
            for(int j = 1; j<=i; j++){
                cout<<"*";
            }
            initialSpace -= 2;
            cout<<endl;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends