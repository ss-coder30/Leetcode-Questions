//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dataTypeSize(string str) {
        // your code here
        char c = 'C';
        int i = 1;
        long l = 2;
        float f = 1.02;
        double d = 1.03;
        if(str == "Character"){
            return sizeof(c);
        }
        else if(str == "Integer"){
            return sizeof(i);
        }
        else if(str == "Long"){
            return sizeof(l);
        }
        else if(str == "Float"){
            return sizeof(f);
        }
        else{
            return sizeof(d);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends