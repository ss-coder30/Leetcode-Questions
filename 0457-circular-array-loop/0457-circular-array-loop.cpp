class Solution {
public:
    bool circularArrayLoop(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // Determine the direction of movement (left or right) based on the sign of the current element
            float direction = std::signbit(nums[i]) ? -1.0 : 1.0;
            int slow = i;
            int fast = i;

            // Use two pointers approach to detect a cycle
            do {
                slow = getNextIndex(nums, direction, slow);
                fast = getNextIndex(nums, direction, fast);

                if (fast != -1)
                    fast = getNextIndex(nums, direction, fast);

            } while (slow != -1 && fast != -1 && slow != fast);

            // Check if a cycle is found and if the cycle has more than one element
            if (slow != -1 && slow == fast)
                return true;
        }
        return false;
    }

private:
    int getNextIndex(const std::vector<int>& nums, float direction, int i) {
        // Determine the direction of the next movement
        float currentDirection = std::signbit(nums[i]) ? -1.0 : 1.0;

        // If the directions are opposite, return -1 as it is not a valid movement
        if (currentDirection * direction < 0)
            return -1;

        int n = nums.size();
        // Calculate the next index
        int nextIndex = (i + nums[i]) % n;

        // Adjust the index if it becomes negative
        if (nextIndex < 0)
            nextIndex += n;

        // Return -1 if the next index points to the same element
        return (nextIndex == i) ? -1 : nextIndex;
    }
};