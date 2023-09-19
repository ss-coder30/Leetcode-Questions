//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        
        // vector<int> binaryNum;
        
        // int a = 0;
        
        // int ans = n | a;
        
        // while(ans > 0){
        //     int rem = ans%2;
        //     binaryNum.emplace_back(rem);
            
        //     ans /= 2;
        // }
        
        // int num = binaryNum.size();
        // int index = 0;
        
        // for(int i = num-1; i>=0; i--){
        //     if(binaryNum[i] == 1){
        //         index = (num-1) - i;
        //         break;
        //     }
        // }
        
        // return index;
        
        
         if (n == 0)
            return 0;

        // Find the rightmost set bit position (1-based indexing).
        int position = 1;
        while (!(n & 1))
        {
            n >>= 1;
            position++;
        }

        return position;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends