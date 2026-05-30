#include <vector>
#include <algorithm>

class Solution {
private:
    bool isSorted(const std::vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != i) return false;
        }
        return true;
    }

    int getRotationOps(const std::vector<int>& arr, bool reverseAtEnd) {
        int n = arr.size();
        int idx0 = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) { idx0 = i; break; }
        }

        int rotations = reverseAtEnd ? (idx0 + 1) % n : idx0;
        
        std::vector<int> simulated(n);
        for (int i = 0; i < n; ++i) {
            simulated[i] = arr[(rotations + i) % n];
        }

        if (reverseAtEnd) {
            std::reverse(simulated.begin(), simulated.end());
        }

        if (isSorted(simulated)) {
            return reverseAtEnd ? (rotations + 1) : rotations;
        }
        
        return 2e9;
    }

public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int min_ops = 2e9;

        // PATH 1: Try without reversing first (Scenarios A & B)
        min_ops = std::min(min_ops, getRotationOps(nums, false));
        min_ops = std::min(min_ops, getRotationOps(nums, true));

        // PATH 2: Try reversing the array first (Scenarios C & D)
        std::vector<int> rev_nums = nums;
        std::reverse(rev_nums.begin(), rev_nums.end());

        min_ops = std::min(min_ops, 1 + getRotationOps(rev_nums, false));
        min_ops = std::min(min_ops, 1 + getRotationOps(rev_nums, true));

        return (min_ops >= 2e9) ? -1 : min_ops;
    }
};