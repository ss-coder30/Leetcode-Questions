class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int h = n - 1, l = 0;

        // Move the high pointer to the last element that is in ascending order
        for (int i = h; i >= 1; i--) {
            if (arr[i] >= arr[i - 1] && h > 0) {
                h--;
            } else {
                break;
            }
        }

        int res = h;

        // Iterate from the start until the high pointer and find the shortest subarray
        for (l = 0; l < h && (l == 0 || arr[l - 1] <= arr[l]); l++) {
            while (h < n && arr[l] > arr[h]) {
                h++;
            }

            res = std::min(res, h - l - 1);
        }

        return res;
    }
};