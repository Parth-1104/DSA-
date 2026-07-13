

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        unordered_map<int, int> counts;
        int max_length = 0;

       
        for (int num : nums) {
            counts[num]++;
        }

        
        for (auto const& [num, count] : counts) {
            
            if (counts.find(num + 1) != counts.end()) {
                max_length = max(max_length, count + counts[num + 1]);
            }
        }

        return max_length;
    }
};