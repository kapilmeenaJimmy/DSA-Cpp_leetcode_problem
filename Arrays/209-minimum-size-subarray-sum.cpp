#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];

            while (currentSum >= target) {
                minLen = std::min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int target1 = 7;
    std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    std::cout << "Test 1 Output: " << sol.minSubArrayLen(target1, nums1) << " (Expected: 2)" << std::endl;

    // Test Case 2
    int target2 = 4;
    std::vector<int> nums2 = {1, 4, 4};
    std::cout << "Test 2 Output: " << sol.minSubArrayLen(target2, nums2) << " (Expected: 1)" << std::endl;

    // Test Case 3
    int target3 = 11;
    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "Test 3 Output: " << sol.minSubArrayLen(target3, nums3) << " (Expected: 0)" << std::endl;

    return 0;
}
