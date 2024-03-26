#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int asteroid : asteroids) {
            // Handle positive asteroids
            if(asteroid > 0) {
                st.push(asteroid);
            } 
            else {
                // Handle negative asteroids
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroid)) {
                    st.pop(); // Destroy smaller positive asteroid
                }
                
                if(!st.empty() && st.top() == abs(asteroid)) {
                    st.pop(); // Destroy both asteroids if they are equal
                } 
                else if(st.empty() || st.top() < 0) {
                    st.push(asteroid); // Negative asteroid survives
                }
            }
        }
        
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};
