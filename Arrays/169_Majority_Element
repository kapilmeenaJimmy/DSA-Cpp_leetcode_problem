#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Majority Element: " << sol.majorityElement(nums) << std::endl; // Expected: 2

    return 0;
}
