#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);

        // Left to right: prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Right to left: suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = sol.productExceptSelf(nums);

    std::cout << "Output: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Expected: 24 12 8 6

    return 0;
}
