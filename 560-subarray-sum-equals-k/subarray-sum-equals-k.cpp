class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // Create prefix array of size n+1 to cleanly handle the 'left-1' case
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int count = 0;
        // Check ALL pairs of left and right (including when left == right)
        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                // Sum of subarray from left to right is prefix[right+1] - prefix[left]
                if (prefix[right + 1] - prefix[left] == k) {
                    count++; // Just add 1 for finding a valid subarray
                }
            }
        }

        return count;
    }
};