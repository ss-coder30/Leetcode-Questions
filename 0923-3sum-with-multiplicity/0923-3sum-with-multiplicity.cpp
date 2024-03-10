class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        const int mod = 1000000007;
        long long ans = 0;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i<n; i++){
            int T = target - arr[i];
            int j = i+1, k = n-1;
            
            while(j < k){
                if(arr[j] + arr[k] < T) j++;
                else if(arr[j] + arr[k] > T) k--;
                else if(arr[j] != arr[k]){
                    int left = 1, right = 1;
                    while(j+1 < k && arr[j] == arr[j+1]){
                        j++;
                        left++;
                    }
                    
                    while(k-1 > j && arr[k] == arr[k-1]){
                        k--;
                        right++;
                    }
                    
                    ans += left*right;
                    ans %= mod;
                    j++;
                    k--;
                }
                else{
                    int m = (k - j + 1);
                    ans += m*(m-1)/2;
                    ans %= mod;
                    break;
                }
            }
        }
        
        return static_cast<int>(ans);
    }
};